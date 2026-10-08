// handwritten.c - the original Cye bootstrap compiler

// BUILD: gcc -mconsole -nostdlib -o handwritten.exe -e_start -Wall -Wextra handwritten.c -lkernel32

#include <stddef.h>
#include <stdint.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

typedef union Char64 Char64;

union Char64
{
  u64  as_u64;
  char as_cstring[9];
};

#define CSTRING(cstring) ((u8 *)(cstring))
#define CHAR64(cstring) (((Char64){ .as_cstring = cstring }).as_u64)

#define STRINGIFY_AS_IS(x)  #x
#define STRINGIFY(x)  STRINGIFY_AS_IS(x)
#define SIZE_COMMA_TEXT(x)  ((s64)sizeof(x) - 1), (u8 *)(x)

#define debug_assert(_true)  \
  do if (!(_true)) say_and_die(SIZE_COMMA_TEXT("\n" __FILE__ ":" STRINGIFY(__LINE__) ": fail: debug_assert(" #_true ");\n\n")); while (0)

#define resource_assert(_true)  \
  do if (!(_true)) say_and_die(SIZE_COMMA_TEXT("\n" __FILE__ ":" STRINGIFY(__LINE__) ": fail: resource_assert(" #_true ");\n\n")); while (0)

#define error_assert(_true)  \
  do if (!(_true)) say_and_die(SIZE_COMMA_TEXT("\n" __FILE__ ":" STRINGIFY(__LINE__) ": fail: error_assert(" #_true ");\n\n")); while (0)

extern void  ExitProcess(u32 status);
extern u8   *GetCommandLineA(void);
extern void *GetStdHandle(s32 std_handle); /* INVALID_HANDLE_VALUE or NULL */
extern s32   WriteFile(void *file_handle, void *data, u32 size, u32 *size_out_opt, void *overlapped_in_out_opt); /* FALSE */
extern s32   ReadFile(void *file_handle, void *data_out, u32 size, u32 *size_out, void *overlapped_in_out_opt); /* FALSE */
extern void *VirtualAlloc(void *base, u64 size, u32 allocation_flags, u32 protect_flags); /* NULL */
extern void *CreateFileA(u8 *cpath, u32 access, u32 share, void *security_opt, u32 disposition, u32 flags, void *template_opt); /* INVALID_HANDLE_VALUE */
extern s32   CloseHandle(void *handle); /* FALSE */
extern u32   GetFileSize(void *file_handle, u32 *size_most_significant_part_out_opt); /* INVALID_FILE_SIZE  */
extern s32   GetConsoleMode(void *console_handle, u32 *mode_flags_out);
extern s32   SetConsoleMode(void *console_handle, u32 mode_flags);

static void say_and_die(s64 size, u8 *text)
{
  WriteFile(GetStdHandle(-12), text, size, NULL, NULL);
  ExitProcess(1);
}

// ASCII characters

static u32 ascii_is_space(u32 c)
{
  return (c == ' ' || c == '\n');
}

static u32 ascii_is_letter(u32 c)
{
  return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

static u32 ascii_is_letter_or_digit(u32 c)
{
  return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9'));
}

static u32 ascii_is_decimal_digit(u32 c)
{
  return ('0' <= c && c <= '9');
}

static u32 ascii_is_uppercase_hexadecimal_digit(u32 c)
{
  return (('A' <= c && c <= 'F') || ('0' <= c && c <= '9'));
}

static u32 ascii_digit_from_int(s64 number)
{
  debug_assert(number >= 0);
  debug_assert(number < 16);
  
  return (number < 10) ? number + '0' : number + 'A' - 10;
}

static u32 ascii_digit_to_int(u32 c)
{
  if ('A' <= c && c <= 'F') return c - 'A' + 10;
  if ('a' <= c && c <= 'f') return c - 'a' + 10;
  if ('0' <= c && c <= '9') return c - '0';
  
  return 100;
}

// process

static void process_exit(u32 status)
{
  ExitProcess(status);
}

// cstring

static s64 cstring_length(u8 *s)
{
  debug_assert(s != NULL);
  
  u8 *s0 = s;
  
  while (*s != '\0')
    s += 1;
  
  return s - s0;
}

// memory

static u32 memory_equal(void *a, void *b, s64 size)
{
  debug_assert(size >= 0);
  debug_assert(size == 0 || a != NULL);
  debug_assert(size == 0 || b != NULL);
  
  for (s64 i = 0; i < size; i += 1)
    if ( ((u8 *)a)[i] != ((u8 *)b)[i] )
      return 0;
  
  return 1;
}

static void memory_copy(void *dst, void *src, s64 size)
{
  debug_assert(size >= 0);
  debug_assert(size == 0 || dst != NULL);
  debug_assert(size == 0 || src != NULL);
  
  for (s64 i = 0; i < size; i += 1)
    ((u8 *)dst)[i] = ((u8 *)src)[i];
}

#if 0
static void memory_move(void *dst, void *src, s64 size)
{
  debug_assert(size >= 0);
  debug_assert(size == 0 || dst != NULL);
  debug_assert(size == 0 || src != NULL);
  
  if ((s64)dst <= (s64)src)
  {
    for (s64 i = 0; i < size; i += 1)
      ((u8 *)dst)[i] = ((u8 *)src)[i];
  }
  else
  {
    for (s64 ri = size - 1; ri >= 0; ri -= 1)
      ((u8 *)dst)[ri] = ((u8 *)src)[ri];
  }
}
#endif

static void memory_set_every_byte_to_value(void *a, u32 value, s64 size)
{
  debug_assert(size >= 0);
  debug_assert(value <= 0xFF);
  debug_assert(size == 0 || a != NULL);
  
  for (s64 i = 0; i < size; i += 1)
    ((u8 *)a)[i] = value;
}

static void memory_zero(void *a, s64 size)
{
  debug_assert(size >= 0);
  debug_assert(size == 0 || a != NULL);
  
  return memory_set_every_byte_to_value(a, 0, size);
}

// arena

typedef struct Arena Arena;

struct Arena
{
  u8  *at;
  s64  pushed;
  s64  commited;
  s64  reserved;
};

static Arena *arena_create(s64 min_reserved)
{
  debug_assert(min_reserved >= 0);
  debug_assert(min_reserved < (s64)1 << 40);
  
  s64 one_page = 0x1000;
  s64 reserved = one_page;
  s64 commited = one_page;
  
  while (reserved < min_reserved)
    reserved *= 2;
  
  s64 true_reserved = one_page + reserved;
  s64 true_commited = one_page + commited;
  
  void *p_0 = VirtualAlloc(NULL, true_reserved, 0x00002000, 0x04); // MEM_RESERVE, PAGE_READWRITE
  resource_assert(p_0 != NULL);
  
  void *p_1 = VirtualAlloc(p_0, true_commited, 0x00001000, 0x04); // MEM_COMMIT, PAGE_READWRITE
  resource_assert(p_1 != NULL);
  
  Arena *arena = p_0;
  
  arena->at = (u8 *)p_0 + one_page;
  arena->reserved = reserved;
  arena->commited = commited;
  arena->pushed = 0;
  
  return arena;
}

static void *arena_get_top(Arena *arena)
{
  debug_assert(arena != NULL);
  
  return arena->at + arena->pushed;
}

static void *arena_push_uninited(Arena *arena, s64 size)
{
  debug_assert(arena != NULL);
  debug_assert(size >= 0);
  
  void *result = arena_get_top(arena);
  arena->pushed += size;
  
  while (arena->commited < arena->pushed)
  {
    s64 commited = arena->commited;
    void *new_half = arena->at + commited;
    
    arena->commited *= 2;
    resource_assert(arena->commited <= arena->reserved);
    
    void *p_0 = VirtualAlloc(new_half, commited, 0x00001000, 0x04); // MEM_COMMIT, PAGE_READWRITE
    resource_assert(p_0 != NULL);
  }
  
  return result;
}

static void *arena_push(Arena *arena, s64 size)
{
  debug_assert(arena != NULL);
  debug_assert(size >= 0);
  
  void *result = arena_push_uninited(arena, size);
  memory_zero(result, size);
  
  return result;
}

static void arena_push_aligner(Arena *arena, s64 alignment)
{
  debug_assert(arena != NULL);
  debug_assert(alignment >= 1);
  
  s64 remainder = arena->pushed % alignment;
  
  if (remainder > 0)
    arena_push(arena, alignment - remainder);
}

static void *arena_push_copy(Arena *arena, s64 size, void *data)
{
  debug_assert(arena != NULL);
  debug_assert(size >= 0);
  debug_assert(data != NULL || size == 0);
  
  void *result = arena_push_uninited(arena, size);
  memory_copy(result, data, size);
  
  return result;
}

static void arena_pop_to_pointer(Arena *arena, void *ptr)
{
  debug_assert(arena != NULL);
  debug_assert(ptr != NULL);
  
  s64 new_pushed = (u8 *)ptr - arena->at;
  
  debug_assert(new_pushed >= 0);
  debug_assert(new_pushed <= arena->pushed);
  
  arena->pushed = new_pushed;
}

//

static s64 arena_print_bytes(Arena *arena, s64 size, void *data)
{
  debug_assert(arena != NULL);
  debug_assert(size >= 0);
  debug_assert(data != NULL || size == 0);
  
  arena_push_copy(arena, size, data);
  return size;
}

static s64 arena_print_cstring(Arena *arena, u8 *cstring)
{
  debug_assert(arena != NULL);
  debug_assert(cstring != NULL);
  
  return arena_print_bytes(arena, cstring_length(cstring), cstring);
}

static s64 arena_print_row(Arena *arena, s64 size, u32 ch)
{
  debug_assert(arena != NULL);
  debug_assert(size >= 0);
  
  void *bytes = arena_push(arena, size);
  memory_set_every_byte_to_value(bytes, ch, size);
  
  return size;
}

static s64 arena_print_u64(Arena *arena, u64 number, u64 base, s64 min_length)
{
  debug_assert(arena != NULL);
  debug_assert(base >= 2);
  debug_assert(base <= 16);
  debug_assert(min_length >= 0);
  
  s64 size = 1;
  s64 copy = number / base;
  
  while (copy > 0)
  {
    size += 1;
    copy /= base;
  }
  
  if (size < min_length)
  {
    arena_print_row(arena, min_length - size, '0');
  }
  
  u8 *chars = arena_push(arena, size);
  
  for (s64 ri = size - 1; ri >= 0; ri -= 1)
  {
    chars[ri] = ascii_digit_from_int(number % base);
    number /= base;
  }
  
  return size;
}

static s64 arena_print_s64(Arena *arena, s64 number, u64 base, s64 min_length)
{
  debug_assert(arena != NULL);
  debug_assert(base >= 2);
  debug_assert(base <= 16);
  debug_assert(min_length >= 0);
  
  s64 result = 0;
  
  if (number < 0)
  {
    result += 1;
    number *= -1;
    min_length = (min_length > 0) ? min_length - 1 : 0;
  }
  
  result += arena_print_u64(arena, number, base, min_length);
  
  return result;
}

static s64 arena_print_char64(Arena *arena, u64 ch)
{
  debug_assert(arena != NULL);
  
  s64 max_length = 0;
  
  for (s64 i = 0; i < (s64)sizeof(ch); i += 1)
    if ( ((ch >> (i * 8)) & 0xFF) != 0 )
      max_length = i + 1;
  
  u8 *chars = arena_push(arena, max_length);
  
  for (s64 i = 0; i < max_length; i += 1)
    chars[i] = ((ch >> (i * 8)) & 0xFF);
  
  return max_length;
}

// file system

static void *file_read_all_bytes(u8 *cpath, Arena *result_arena)
{
  debug_assert(cpath != NULL);
  debug_assert(result_arena != NULL);
  
  void *result = NULL;
  
  void *file_handle = CreateFileA(cpath, 0x80000000, 0, NULL, 3, 128, NULL); /* GENERIC_READ, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL */
  
  if (file_handle != ((void *)~(u64)0)) // INVALID_HANDLE_VALUE
  {
    u32 file_size = GetFileSize(file_handle, NULL);
    s64 valid_file_size = (file_size != 0xFFFFFFFF) ? file_size : 0; // INVALID_FILE_SIZE
    
    u8 *file_content = arena_push(result_arena, valid_file_size);
    
    u32 file_size_out = 0;
    s32 ok_0 = ReadFile(file_handle, file_content, valid_file_size, &file_size_out, NULL);
    
    s32 ok_1 = (valid_file_size == file_size_out);
    
    s32 ok_2 = CloseHandle(file_handle);
    
    if (ok_0 && ok_1 && ok_2)
    {
      result = file_content;
    }
    else
    {
      arena_pop_to_pointer(result_arena, file_content);
    }
  }
  
  return result;
}

static u32 file_write_all_bytes(u8 *cpath, s64 size, void *data)
{
  debug_assert(cpath != NULL);
  debug_assert(size >= 0);
  debug_assert(size < 0x10000000);
  debug_assert(data != NULL || size == 0);
  
  u32 result = 0;
  
  void *file_handle = CreateFileA(cpath, 0x40000000, 0, NULL, 2, 128, NULL); // GENERIC_WRITE, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL
  
  if (file_handle != ((void *)~(u64)0)) // INVALID_HANDLE_VALUE
  {
    s32 ok_0 = WriteFile(file_handle, data, size, NULL, NULL);
    s32 ok_1 = CloseHandle(file_handle);
    
    result = (ok_0 && ok_1);
  }
  
  return result;
}

// console

static void *console_get_error_stream(void)
{
  return GetStdHandle(-12);
}

#if 0
static void *console_get_output_stream(void)
{
  return GetStdHandle(-11);
}
#endif

#if 0
static void *console_get_input_stream(void)
{
  return GetStdHandle(-10);
}
#endif

static void console_error_print_bytes(s64 size, void *data)
{
  debug_assert(size >= 0);
  debug_assert(data != NULL || size == 0);
  
  WriteFile(console_get_error_stream(), data, size, NULL, NULL);
}

static void console_error_print_cstring(u8 *cstring)
{
  debug_assert(cstring != NULL);
  
  console_error_print_bytes(cstring_length(cstring), cstring);
}

static void console_init(void)
{
  u32 prev_mode = 0;
  s32 ok_0 = GetConsoleMode(console_get_error_stream(), &prev_mode);
  resource_assert(ok_0);
  
  // DISABLE_NEWLINE_AUTO_RETURN 0x0008
  s32 ok_1 = SetConsoleMode(console_get_error_stream(), prev_mode | 0x0004); // ENABLE_VIRTUAL_TERMINAL_PROCESSING
  resource_assert(ok_1);
}

// command

static u8 **command_get_arguments(Arena *result_arena, Arena *temp_arena)
{
  s64 num_arguments = 0;
  
  u8 *command_line = GetCommandLineA();
  u8 *cp = command_line;
  
  u8 *temp_arena_beg = arena_get_top(temp_arena);
  
  while (*cp != '\0')
  {
    while (*cp == ' ')
      cp += 1;
    
    u8 *argument_beg = cp;
    
    while (*cp != ' ' && *cp != '\0')
      cp += 1;
    
    u8 *argument_end = cp;
    s64 argument_size = argument_end - argument_beg;
    
    u8 *argument_value = arena_push_copy(result_arena, argument_size, argument_beg);
    arena_push(result_arena, 1);
    
    arena_push_copy(temp_arena, sizeof(argument_value), &argument_value);
    num_arguments += 1;
  }
  
  arena_push_aligner(result_arena, sizeof(u8 *));
  u8 **result = arena_push_copy(result_arena, num_arguments * sizeof(u8 *), temp_arena_beg);
  arena_push(result_arena, sizeof(u8 *));
  
  arena_pop_to_pointer(temp_arena, temp_arena_beg);
  
  return result + 1;
}

//

static s64 s64_align(s64 number, s64 alignment)
{
  debug_assert(alignment >= 1);
  
  s64 remainder = number % alignment;
  
  return (remainder == 0) ? number : number + alignment - remainder;
}

//
// NOTE: no one below this comment can use Windows API directly:
//

typedef struct Token Token;
typedef struct Ast_Node Ast_Node;
typedef struct Parser Parser;
typedef struct Type Type;
typedef struct Symbol Symbol;
typedef struct Scope Scope;
typedef struct Expr_Value Expr_Value;

//

struct Token
{
  u8  *at;
  s64  size;
  u64  kind;
  u8  *file;
};

enum
{
  COMPLAIN_FATAL_ERROR = 0,
  COMPLAIN_NOTE,
  COMPLAIN_WARNING,
  COMPLAIN_ERROR,
  COMPLAIN_ENUM_COUNT
};

struct Scope
{
  Symbol **symbols;
  s64      num_symbols;
  Scope   *parent;
};

struct Expr_Value
{
  Token *token;
  Type  *type;
  u64    as_u64;
  u32    is_lvalue;
  u32    is_constexpr;
};

struct Ast_Node
{
  u64         kind;
  Token      *token;
  Expr_Value  value;
  
  Ast_Node *expr_0;
  // unary
  // lhs in binary
  // function in a call
  // returned value (opt.)
  // returned type (opt.)
  // condition in while/do-while/if
  // c_for init
  
  Ast_Node *expr_1;
  // rhs in binary
  // c_for condition
  
  Ast_Node *expr_2;
  // c_for reinit
  
  Ast_Node *stmt_0;
  // function body
  // if true
  // while
  // do-while
  // c_for
  
  Ast_Node *stmt_1;
  // else
  
  s64        num_items;
  Ast_Node **items;
  // arguments
  // parameters
  // statements
  // globals
  
  Symbol *symbol_by_name; // kind == CHAR64("name")
  Scope   scope; // kind == CHAR64("stmtlist") || kind == CHAR64("root")
  
  u8 *struct_c_name;
};

struct Parser
{
  Token *before_first;
  Token *after_last;
  Token *tokens;
  s64    num_tokens;
  s64    index;
};

struct Type
{
  u64    kind;
  Token *token;
  Token *name_token_opt;
  u8    *c_name_opt;
  u8    *struct_c_name;
  
  Type   *sub_type;
  
  s64     num_params;
  Type  **params;
  
  s64     num_members;
  Type  **members;
};

enum
{
  STORAGE_UNDEFINED,
  STORAGE_STATIC,
  STORAGE_EXTERN,
  STORAGE_LOCAL,
  STORAGE_C_TYPEDEF,
  STORAGE_C_ENUM,
};

struct Symbol
{
  Token    *token;
  Type     *type;
  Ast_Node *ast_node;
  u8       *c_name;
  Token    *c_extern;
  Token    *c_typedef;
  u32       storage;
  u32       local_is_active; // STORAGE_LOCAL only
  s64       num_uses;
  s64       c_enum_value; // STORAGE_C_ENUM only
};

//

static s64 g_next_address;
static u32 option_print_actual_names = 1;

static Arena *keep_arena;
static Arena *temp_arena_0;
static Arena *temp_arena_1;

//

static Arena *get_temp_arena(Arena *but_not_this_one)
{
  return (temp_arena_0 != but_not_this_one) ? temp_arena_0 : temp_arena_1;
}

static s64 arena_print_address(Arena *arena, s64 address)
{
  s64 len = 0;
  
  len += arena_print_cstring(arena, CSTRING("A_"));
  len += arena_print_u64(arena, address, 16, 5);
  
  return len;
}

//

static void complain(u32 complain_kind, Token *token_opt, u8 *message)
{
  debug_assert(message != NULL);
  debug_assert(complain_kind < COMPLAIN_ENUM_COUNT);
  
  // begin
  
  Arena *text_arena = get_temp_arena(NULL);
  
  u8 *text = arena_get_top(text_arena);
  
  //
  
  s64 row = 0;
  s64 col = 0;
  
  if (token_opt != NULL)
  {
    row = 1;
    col = 1;
    
    for (s64 i = 0; token_opt->file + i != token_opt->at; i += 1)
    {
      if (token_opt->file[i] == '\n')
      {
        row += 1;
        col = 0;
      }
      
      col += 1;
    }
    
    arena_print_cstring(text_arena, CSTRING("\x1B[93m"));
    arena_print_s64(text_arena, row, 10, 0);
    arena_print_cstring(text_arena, CSTRING(":"));
    arena_print_s64(text_arena, col, 10, 0);
    arena_print_cstring(text_arena, CSTRING(": "));
  }
  
  u8 *kind_as_color = NULL;
  u8 *kind_as_cstring = NULL;
  
  if (complain_kind == COMPLAIN_ERROR || complain_kind == COMPLAIN_FATAL_ERROR)
  {
    kind_as_color   = CSTRING("\x1B[91m");
    kind_as_cstring = CSTRING("\x1B[91merror:\x1B[0m");
  }
  else if (complain_kind == COMPLAIN_NOTE)
  {
    kind_as_color   = CSTRING("\x1B[96m");
    kind_as_cstring = CSTRING("\x1B[96mnote:\x1B[0m");
  }
  else if (complain_kind == COMPLAIN_WARNING)
  {
    kind_as_color   = CSTRING("\x1B[95m");
    kind_as_cstring = CSTRING("\x1B[95mwarning:\x1B[0m");
  }
  
  arena_print_cstring(text_arena, kind_as_cstring);
  arena_print_cstring(text_arena, CSTRING(" "));
  arena_print_cstring(text_arena, message);
  arena_print_cstring(text_arena, CSTRING("\n"));
  
  if (token_opt != NULL)
  {
    arena_print_cstring(text_arena, CSTRING(" "));
    s64 size_0 = arena_print_s64(text_arena, row, 10, 0);
    arena_print_cstring(text_arena, CSTRING(" | "));
    
    u8 *line = token_opt->at - (col - 1);
    s64 line_size = 0;
    
    while (line[line_size] != '\0' && line[line_size] != '\n')
      line_size += 1;
    
    s64 size_1 = arena_print_bytes(text_arena, col - 1, line);
    
    arena_print_cstring(text_arena, kind_as_color);
    s64 size_2 = arena_print_bytes(text_arena, token_opt->size, token_opt->at);
    arena_print_cstring(text_arena, CSTRING("\x1B[0m"));
    
    arena_print_bytes(text_arena, line_size - (size_1 + size_2), line + (size_1 + size_2));
    
    arena_print_cstring(text_arena, CSTRING("\n"));
    
    arena_print_row(text_arena, size_0 + 2, ' ');
    arena_print_cstring(text_arena, CSTRING("|"));
    arena_print_row(text_arena, col, ' ');
    
    arena_print_cstring(text_arena, kind_as_color);
    arena_print_cstring(text_arena, CSTRING("^"));
    
    if (token_opt->size > 1)
      arena_print_row(text_arena, token_opt->size - 1, '~');
    
    arena_print_cstring(text_arena, CSTRING("\x1B[0m\n"));
  }
  
  // end
  
  console_error_print_bytes((u8 *)arena_get_top(text_arena) - text, text);
  arena_pop_to_pointer(text_arena, text);
  
  if (complain_kind == COMPLAIN_FATAL_ERROR)
    process_exit(1);
}

//

static s64 parser_tokens_left(Parser *parser)
{
  debug_assert(parser != NULL);
  
  return parser->num_tokens - parser->index;
}

static Token *parser_at(Parser *parser, s64 relative_index)
{
  debug_assert(parser != NULL);
  
  s64 absolute_index = parser->index + relative_index;
  
  debug_assert(absolute_index >= 0);
  debug_assert(absolute_index < parser->num_tokens);
  
  return parser->tokens + absolute_index;
}

static Token *parser_safe_at(Parser *parser, s64 relative_index)
{
  debug_assert(parser != NULL);
  
  s64 absolute_index = parser->index + relative_index;
  
  Token *result = NULL;
  
  if (absolute_index < 0)
  {
    result = parser->before_first;
  }
  else if (absolute_index >= parser->num_tokens)
  {
    result = parser->after_last;
  }
  else
  {
    result = parser_at(parser, relative_index);
  }
  
  return result;
}

static void parser_proceed(Parser *parser)
{
  debug_assert(parser != NULL);
  
  if (parser->index < parser->num_tokens)
    parser->index += 1;
}

static Token *parser_inspect(Parser *parser, u64 token_kind)
{
  debug_assert(parser != NULL);
  
  Token *curr = parser_safe_at(parser, 0);
  
  if (curr->kind != token_kind)
    return NULL;
  
  return curr;
}

static Token *parser_accept(Parser *parser, u64 token_kind)
{
  debug_assert(parser != NULL);
  
  Token *curr = parser_safe_at(parser, 0);
  
  if (curr->kind != token_kind)
    return NULL;
  
  parser_proceed(parser);
  return curr;
}

static Token *parser_expect(Parser *parser, u64 token_kind, u8 *what)
{
  debug_assert(parser != NULL);
  debug_assert(what != NULL);
  
  Token *curr = parser_safe_at(parser, 0);
  
  if (curr->kind != token_kind)
  {
    Arena *temp_arena = get_temp_arena(NULL);
    
    u8 *message = arena_get_top(temp_arena);
    arena_print_cstring(temp_arena, CSTRING("expected "));
    arena_print_cstring(temp_arena, what);
    arena_push(temp_arena, 1);
    
    complain(0, curr, message);
    
    arena_pop_to_pointer(temp_arena, message);
  }
  
  parser_proceed(parser);
  return curr;
}

static Ast_Node *ast_create_node(u64 ast_kind_opt, Token *token_opt)
{
  arena_push_aligner(keep_arena, alignof(Ast_Node));
  Ast_Node *result = arena_push(keep_arena, sizeof(Ast_Node));
  
  result->kind = ast_kind_opt;
  result->token = token_opt;
  
  return result;
}

/*
the operator precedence:
0.  x(...)  x[i]  x.*  x.&  x.y
1.  +x  -x  ^x  *x  not x  size_of x  alignment_of x
2.  +  -  *  /  %  &  |  ^  <<  >>
3.  ==  !=  <=  >=  <  >
4.  and
5.  or
6.  =  +=  -=  *=  /=  %=  &=  |=  ^=  <<=  >>=
7.  :
8.  c_name x y   c_extern x
*/

static Ast_Node *parse_expression(Parser *parser, u32 minimal_precedence)
{
  Ast_Node *lhs = NULL;
  
  u64 prefix_kind = 0;
  u32 prefix_precedence = 0;
  
  if (0) {}
  else if (parser_inspect(parser, CHAR64("+"       ))) { prefix_kind = CHAR64("+a"      ); prefix_precedence = 0x100; }
  else if (parser_inspect(parser, CHAR64("-"       ))) { prefix_kind = CHAR64("-a"      ); prefix_precedence = 0x100; }
  else if (parser_inspect(parser, CHAR64("^"       ))) { prefix_kind = CHAR64("^a"      ); prefix_precedence = 0x100; }
  else if (parser_inspect(parser, CHAR64("*"       ))) { prefix_kind = CHAR64("*a"      ); prefix_precedence = 0x100; }
  else if (parser_inspect(parser, CHAR64("not"     ))) { prefix_kind = CHAR64("not a"   ); prefix_precedence = 0x100; }
  else if (parser_inspect(parser, CHAR64("size_of" ))) { prefix_kind = CHAR64("size_of" ); prefix_precedence = 0x100; }
  else if (parser_inspect(parser, CHAR64("align_of"))) { prefix_kind = CHAR64("align_of"); prefix_precedence = 0x100; }
  
  
  /**/ if (prefix_kind != 0)
  {
    parser_proceed(parser);
    lhs = ast_create_node(prefix_kind, parser_at(parser, -1));
    lhs->expr_0 = parse_expression(parser, prefix_precedence);
  }
  else if (parser_accept(parser, CHAR64("struct")))
  {
    lhs = ast_create_node(CHAR64("struct"), parser_at(parser, -1));
    
    g_next_address += 1;
    s64 address = g_next_address;
    lhs->struct_c_name = arena_get_top(keep_arena);
    arena_print_address(keep_arena, address);
    arena_push(keep_arena, 1);
    
    Arena *temp_arena = get_temp_arena(NULL);
    void *members = arena_get_top(temp_arena);
    
    parser_expect(parser, CHAR64("{"), CSTRING("the openning curly brace '{' of the struct"));
    
    while (parser_tokens_left(parser) > 0 && !parser_inspect(parser, CHAR64("}")))
    {
      Ast_Node *member = parse_expression(parser, 0);
      parser_expect(parser, CHAR64(";"), CSTRING("the semicolon ';' after the member declaration"));
    
      arena_push_copy(temp_arena, sizeof(member), &member);
      lhs->num_items += 1;
    }
    
    parser_expect(parser, CHAR64("}"), CSTRING("the closing curly brace '}' of the struct"));
    
    arena_push_aligner(keep_arena, alignof(Ast_Node *));
    lhs->items = arena_push_copy(keep_arena, lhs->num_items * sizeof(Ast_Node *), members);
    arena_pop_to_pointer(temp_arena, members);
  }
  else if (parser_accept(parser, CHAR64("c_string")))
  {
    Token *the_string = parser_expect(parser, CHAR64("\""), CSTRING("the string constant after c_string"));
    lhs = ast_create_node(CHAR64("c_string"), the_string);
  }
  else if (parser_accept(parser, CHAR64("name"))
        || parser_accept(parser, CHAR64("u64" ))
        || parser_accept(parser, CHAR64("u32" ))
        || parser_accept(parser, CHAR64("u32" ))
        || parser_accept(parser, CHAR64("u8"  ))
        || parser_accept(parser, CHAR64("s64" ))
        || parser_accept(parser, CHAR64("s32" ))
        || parser_accept(parser, CHAR64("s16" ))
        || parser_accept(parser, CHAR64("s8"  ))
        || parser_accept(parser, CHAR64("void"))
        || parser_accept(parser, CHAR64("null"))
        || parser_accept(parser, CHAR64("c_dbgpos"))
        || parser_accept(parser, CHAR64("'"))
        || parser_accept(parser, CHAR64("integer")))
  {
    lhs = ast_create_node(parser_at(parser, -1)->kind, parser_at(parser, -1));
  }
  else if (parser_accept(parser, CHAR64("c_extern")))
  {
    Token *c_extern_token = parser_at(parser, -1);
    lhs = parse_expression(parser, 0);
    
    if (lhs->kind != CHAR64("a:b"))
      complain(0, lhs->token, CSTRING("not a declaration after c_extern"));
    
    debug_assert(lhs->expr_0->symbol_by_name != NULL);
    lhs->expr_0->symbol_by_name->c_extern = c_extern_token;
  }
  else if (parser_accept(parser, CHAR64("ctypedef")))
  {
    Token *c_typedef_token = parser_at(parser, -1);
    lhs = parse_expression(parser, 0);
    
    if (lhs->kind != CHAR64("a:b"))
      complain(0, lhs->token, CSTRING("not a declaration after c_typedef"));
    
    debug_assert(lhs->expr_0->symbol_by_name != NULL);
    lhs->expr_0->symbol_by_name->c_typedef = c_typedef_token;
  }
  else if (parser_accept(parser, CHAR64("c_name")))
  {
    Token *the_name = parser_expect(parser, CHAR64("name"), CSTRING("the C name"));
    
    lhs = parse_expression(parser, 0);
    
    if (lhs->kind != CHAR64("a:b"))
      complain(0, lhs->token, CSTRING("not a declaration after c_name"));
    
    debug_assert(lhs->expr_0->symbol_by_name != NULL);
    lhs->expr_0->symbol_by_name->c_name = arena_get_top(keep_arena);
    arena_print_bytes(keep_arena, the_name->size, the_name->at);
    arena_push(keep_arena, 1);
  }
  else
  {
    Ast_Node *function = NULL;
    
    Token *token = parser_expect(parser, CHAR64("("), CSTRING("a primary expression"));
    
    if (parser_accept(parser, CHAR64(")")))
    {
      function = ast_create_node(CHAR64("(a)->b"), token);
    }
    else
    {
      Ast_Node *param0_or_subexpr = parse_expression(parser, 0);
      
      if (param0_or_subexpr->kind == CHAR64("a:b"))
      {
        function = ast_create_node(CHAR64("(a)->b"), token);
        Ast_Node *param0 = param0_or_subexpr;
        
        Arena *temp_arena = get_temp_arena(NULL);
        void *params = arena_push_copy(temp_arena, sizeof(param0), &param0);
        function->num_items = 1;
        
        while (parser_accept(parser, CHAR64(",")))
        {
          if (parser_inspect(parser, CHAR64(")")))
            break;
          
          Ast_Node *param = parse_expression(parser, 0);
          arena_push_copy(temp_arena, sizeof(param), &param);
          function->num_items += 1;
        }
        
        parser_expect(parser, CHAR64(")"), CSTRING("the closing parenthesis ')' of the function type"));
        
        arena_push_aligner(keep_arena, alignof(Ast_Node *));
        function->items = arena_push_copy(keep_arena, function->num_items * sizeof(Ast_Node *), params);
        arena_pop_to_pointer(temp_arena, params);
      }
      else
      {
        lhs = param0_or_subexpr;
        parser_expect(parser, CHAR64(")"), CSTRING("the closing parenthesis ')' of the sub-expression"));
      }
    }
    
    if (function)
    {
      function->token = parser_expect(parser, CHAR64("->"), CSTRING("the arrow '->' in the function type"));
      function->expr_0 = parse_expression(parser, 0);
      lhs = function;
    }
  }
  
  for (;;)
  {
    u64 binary_kind = 0;
    u64 postfix_kind = 0;
    u32 precedence = 0;
    u32 right_to_left = 0;
    
    if (0) {}

    else if (parser_inspect(parser, CHAR64("." ))) { binary_kind = CHAR64("a.b" ); precedence = 0x110; }
    
    else if (parser_inspect(parser, CHAR64("+" ))) { binary_kind = CHAR64("a+b" ); precedence = 0x070; }
    else if (parser_inspect(parser, CHAR64("-" ))) { binary_kind = CHAR64("a-b" ); precedence = 0x070; }
    else if (parser_inspect(parser, CHAR64("*" ))) { binary_kind = CHAR64("a*b" ); precedence = 0x070; }
    else if (parser_inspect(parser, CHAR64("/" ))) { binary_kind = CHAR64("a/b" ); precedence = 0x070; }
    else if (parser_inspect(parser, CHAR64("%" ))) { binary_kind = CHAR64("a%b" ); precedence = 0x070; }
    else if (parser_inspect(parser, CHAR64("&" ))) { binary_kind = CHAR64("a&b" ); precedence = 0x070; }
    else if (parser_inspect(parser, CHAR64("^" ))) { binary_kind = CHAR64("a^b" ); precedence = 0x070; }
    else if (parser_inspect(parser, CHAR64("|" ))) { binary_kind = CHAR64("a|b" ); precedence = 0x070; }
    else if (parser_inspect(parser, CHAR64(">>"))) { binary_kind = CHAR64("a>>b"); precedence = 0x070; }
    else if (parser_inspect(parser, CHAR64("<<"))) { binary_kind = CHAR64("a<<b"); precedence = 0x070; }
    
    else if (parser_inspect(parser, CHAR64("=="))) { binary_kind = CHAR64("a==b"); precedence = 0x060; }
    else if (parser_inspect(parser, CHAR64("!="))) { binary_kind = CHAR64("a!=b"); precedence = 0x060; }
    else if (parser_inspect(parser, CHAR64("<="))) { binary_kind = CHAR64("a<=b"); precedence = 0x060; }
    else if (parser_inspect(parser, CHAR64(">="))) { binary_kind = CHAR64("a>=b"); precedence = 0x060; }
    else if (parser_inspect(parser, CHAR64("<" ))) { binary_kind = CHAR64("a<b" ); precedence = 0x060; }
    else if (parser_inspect(parser, CHAR64(">" ))) { binary_kind = CHAR64("a>b" ); precedence = 0x060; }
    
    else if (parser_inspect(parser, CHAR64("and" ))) { binary_kind = CHAR64("a and b" ); precedence = 0x050; }
    
    else if (parser_inspect(parser, CHAR64("or" ))) { binary_kind = CHAR64("a or b" ); precedence = 0x040; }
    
    else if (parser_inspect(parser, CHAR64("="  ))) { binary_kind = CHAR64("a=b"  ); precedence = 0x030; right_to_left = 1; }
    else if (parser_inspect(parser, CHAR64("+=" ))) { binary_kind = CHAR64("a+=b" ); precedence = 0x030; right_to_left = 1; }
    else if (parser_inspect(parser, CHAR64("-=" ))) { binary_kind = CHAR64("a-=b" ); precedence = 0x030; right_to_left = 1; }
    else if (parser_inspect(parser, CHAR64("*=" ))) { binary_kind = CHAR64("a*=b" ); precedence = 0x030; right_to_left = 1; }
    else if (parser_inspect(parser, CHAR64("/=" ))) { binary_kind = CHAR64("a/=b" ); precedence = 0x030; right_to_left = 1; }
    else if (parser_inspect(parser, CHAR64("%=" ))) { binary_kind = CHAR64("a%=b" ); precedence = 0x030; right_to_left = 1; }
    else if (parser_inspect(parser, CHAR64("&=" ))) { binary_kind = CHAR64("a&=b" ); precedence = 0x030; right_to_left = 1; }
    else if (parser_inspect(parser, CHAR64("^=" ))) { binary_kind = CHAR64("a^=b" ); precedence = 0x030; right_to_left = 1; }
    else if (parser_inspect(parser, CHAR64("|=" ))) { binary_kind = CHAR64("a|=b" ); precedence = 0x030; right_to_left = 1; }
    else if (parser_inspect(parser, CHAR64("<<="))) { binary_kind = CHAR64("a<<=b"); precedence = 0x030; right_to_left = 1; }
    else if (parser_inspect(parser, CHAR64(">>="))) { binary_kind = CHAR64("a>>=b"); precedence = 0x030; right_to_left = 1; }
    
    else if (parser_inspect(parser, CHAR64(":"))) { binary_kind = CHAR64("a:b"); precedence = 0x010; right_to_left = 1; }
    
    else if (parser_inspect(parser, CHAR64("(" ))) { postfix_kind = CHAR64("a(b)"); precedence = 0x110; }
    else if (parser_inspect(parser, CHAR64(".&"))) { postfix_kind = CHAR64("a.&" ); precedence = 0x110; }
    else if (parser_inspect(parser, CHAR64(".*"))) { postfix_kind = CHAR64("a.*" ); precedence = 0x110; }
    else if (parser_inspect(parser, CHAR64("[" ))) { postfix_kind = CHAR64("a[b]"); precedence = 0x110; }
    
    /**/ if (postfix_kind != 0)
    {
      if (precedence < minimal_precedence)
        break;
      
      parser_proceed(parser);
      Ast_Node *new_lhs = ast_create_node(postfix_kind, parser_at(parser, -1));
      new_lhs->expr_0 = lhs;
      lhs = new_lhs;
      
      if (postfix_kind == CHAR64("a(b)"))
      {
        Arena *temp_arena = get_temp_arena(NULL);
        void *args = arena_get_top(temp_arena);
        u32 can_continue = 1;
        
        while (parser_tokens_left(parser) > 0 && !parser_inspect(parser, CHAR64(")")) && can_continue)
        {
          Ast_Node *arg = parse_expression(parser, 0);
          arena_push_copy(temp_arena, sizeof(arg), &arg);
          new_lhs->num_items += 1;
          
          can_continue = (parser_accept(parser, CHAR64(",")) != NULL);
        }
        
        arena_push_aligner(keep_arena, alignof(Ast_Node *));
        new_lhs->items = arena_push_copy(keep_arena, new_lhs->num_items * sizeof(Ast_Node *), args);
        arena_pop_to_pointer(temp_arena, args);
        
        parser_expect(parser, CHAR64(")"), CSTRING("the closing parenthesis ')' of the function call"));
      }
      else if (postfix_kind == CHAR64("a[b]"))
      {
        new_lhs->expr_1 = parse_expression(parser, 0);
        error_assert(new_lhs->expr_1->kind != CHAR64("a:b"));
        
        parser_expect(parser, CHAR64("]"), CSTRING("the closing bracket ']' of the index operator"));
      }
    }
    else if (binary_kind == CHAR64("a.b") && parser_safe_at(parser, 1)->kind == CHAR64("cast"))
    {
      if (precedence < minimal_precedence)
        break;
      
      parser_proceed(parser);
      parser_proceed(parser);
      Ast_Node *new_lhs = ast_create_node(CHAR64("cast"), parser_at(parser, -1));
      new_lhs->expr_0 = lhs;
      new_lhs->expr_1 = parse_expression(parser, 0x200);
      lhs = new_lhs;
    }
    else if (binary_kind != 0)
    {
      if (precedence < minimal_precedence)
        break;
      
      parser_proceed(parser);
      Ast_Node *new_lhs = ast_create_node(binary_kind, parser_at(parser, -1));
      new_lhs->expr_0 = lhs;
      new_lhs->expr_1 = parse_expression(parser, precedence + (right_to_left ? 0 : 1));
      lhs = new_lhs;
      
      if (binary_kind == CHAR64("a:b"))
      {
        if (new_lhs->expr_0->kind != CHAR64("name"))
          complain(0, new_lhs->expr_0->token, CSTRING("not a name in the declaration"));
        
        arena_push_aligner(keep_arena, alignof(Symbol));
        Symbol *symbol = arena_push(keep_arena, sizeof(Symbol));
        symbol->token = new_lhs->expr_0->token;
        symbol->ast_node = new_lhs;
        
        g_next_address += 1;
        s64 address = g_next_address;
        symbol->c_name = arena_get_top(keep_arena);
        arena_print_address(keep_arena, address);
        arena_push(keep_arena, 1);
        
        new_lhs->expr_0->symbol_by_name = symbol;
      }
    }
    else
    {
      break;
    }
  }
  
  debug_assert(lhs != NULL);
  return lhs;
}

static Ast_Node *parse_statement(Parser *parser)
{
  Ast_Node *stmt = NULL;
  
  if (parser_accept(parser, CHAR64("{")))
  {
    stmt = ast_create_node(CHAR64("stmtlist"), parser_at(parser, -1));
    
    Arena *temp_arena = get_temp_arena(NULL);
    Ast_Node **sub_stmts = arena_get_top(temp_arena);
    
    while (parser_tokens_left(parser) > 0 && !parser_inspect(parser, CHAR64("}")))
    {
      Ast_Node *sub_stmt = parse_statement(parser);
      arena_push_copy(temp_arena, sizeof(sub_stmt), &sub_stmt);
      stmt->num_items += 1;
    }
    
    parser_expect(parser, CHAR64("}"), CSTRING("XXX"));
    
    arena_push_aligner(keep_arena, alignof(Ast_Node *));
    stmt->items = arena_push_copy(keep_arena, stmt->num_items * sizeof(Ast_Node *), sub_stmts);
    arena_pop_to_pointer(temp_arena, sub_stmts);
  }
  else if (parser_accept(parser, CHAR64("if")))
  {
    stmt = ast_create_node(CHAR64("if-else"), parser_at(parser, -1));
    
    stmt->expr_0 = parse_expression(parser, 0);
    stmt->stmt_0 = parse_statement(parser);
    error_assert(stmt->stmt_0->kind != CHAR64(":"));
    
    if (parser_accept(parser, CHAR64("else")))
    {
      stmt->stmt_1 = parse_statement(parser);
      error_assert(stmt->stmt_1->kind != CHAR64(":"));
    }
  }
  else if (parser_accept(parser, CHAR64("while")))
  {
    stmt = ast_create_node(CHAR64("while"), parser_at(parser, -1));
    
    stmt->expr_0 = parse_expression(parser, 0);
    stmt->stmt_0 = parse_statement(parser);
    error_assert(stmt->stmt_0->kind != CHAR64(":"));
  }
  else if (parser_accept(parser, CHAR64("do")))
  {
    stmt = ast_create_node(CHAR64("do-while"), parser_at(parser, -1));
    
    stmt->stmt_0 = parse_statement(parser);
    error_assert(stmt->stmt_0->kind != CHAR64(":"));
    
    parser_expect(parser, CHAR64("while"), CSTRING("the 'while' keyword in the do-while loop"));
    stmt->expr_0 = parse_expression(parser, 0);
    parser_expect(parser, CHAR64(";"), CSTRING("the semicolon ';' after the condition"));
  }
  else if (parser_accept(parser, CHAR64("c_for")))
  {
    stmt = ast_create_node(CHAR64("c_for"), parser_at(parser, -1));
    
    if (!parser_inspect(parser, CHAR64(";")))
    {
      stmt->expr_0 = parse_expression(parser, 0);
      error_assert(stmt->expr_0->kind != CHAR64(":"));
    }
    
    parser_expect(parser, CHAR64(";"), CSTRING("the semicolon ';' after the init in c_for"));
    
    if (!parser_inspect(parser, CHAR64(";")))
    {
      stmt->expr_1 = parse_expression(parser, 0);
      error_assert(stmt->expr_1->kind != CHAR64(":"));
    }
    
    parser_expect(parser, CHAR64(";"), CSTRING("the semicolon ';' after the condition in c_for"));
    
    if (!parser_inspect(parser, CHAR64(";")))
    {
      stmt->expr_2 = parse_expression(parser, 0);
      error_assert(stmt->expr_2->kind != CHAR64(":"));
    }
    
    parser_expect(parser, CHAR64(";"), CSTRING("the semicolon ';' after the reinit in c_for"));
    
    stmt->stmt_0 = parse_statement(parser);
    error_assert(stmt->stmt_0->kind != CHAR64(":"));
  }
  else if (parser_accept(parser, CHAR64("return")))
  {
    stmt = ast_create_node(CHAR64("return"), parser_at(parser, -1));
    
    stmt->expr_0 = parse_expression(parser, 0);
    parser_expect(parser, CHAR64(";"), CSTRING("the semicolon ';' after the return"));
    error_assert(stmt->expr_0->kind != CHAR64(":"));
  }
  else if (parser_accept(parser, CHAR64("break")))
  {
    stmt = ast_create_node(CHAR64("break"), parser_at(parser, -1));
    parser_expect(parser, CHAR64(";"), CSTRING("the semicolon ';' after the break"));
  }
  else if (parser_accept(parser, CHAR64("continue")))
  {
    stmt = ast_create_node(CHAR64("continue"), parser_at(parser, -1));
    parser_expect(parser, CHAR64(";"), CSTRING("the semicolon ';' after the continue"));
  }
  else
  {
    stmt = parse_expression(parser, 0);
    parser_expect(parser, CHAR64(";"), CSTRING("the semicolon ';' after the expression"));
  }
  
  debug_assert(stmt != NULL);
  return stmt;
}

static void ast_debug_print_recursively(Ast_Node *ast, u64 spaces, u8 *title, s64 index_opt, Arena *result_arena)
{
  arena_print_row(result_arena, spaces, ' ');
  
  if (index_opt >= 0)
  {
    arena_print_cstring(result_arena, CSTRING("["));
    arena_print_s64(result_arena, index_opt, 10, 2);
    arena_print_cstring(result_arena, CSTRING("]  "));
  }
  
  arena_print_cstring(result_arena, title);
  arena_print_cstring(result_arena, CSTRING("  "));
  
  if (ast != NULL)
  {
    if (ast->kind != 0)
    {
      arena_print_char64(result_arena, ast->kind);
      arena_print_cstring(result_arena, CSTRING("  "));
    }
    else
    {
      arena_print_cstring(result_arena, CSTRING("(ast->kind == 0)  "));
    }
    
    if (ast->items != NULL)
    {
      arena_print_cstring(result_arena, CSTRING("items["));
      arena_print_s64(result_arena, ast->num_items, 10, 0);
      arena_print_cstring(result_arena, CSTRING("]  "));
    }
    
    if (ast->scope.symbols != NULL)
    {
      arena_print_cstring(result_arena, CSTRING("symbols["));
      arena_print_s64(result_arena, ast->scope.num_symbols, 10, 0);
      arena_print_cstring(result_arena, CSTRING("]  "));
    }
    
    arena_print_cstring(result_arena, CSTRING("{ "));
    
    if (ast->token != NULL)
    {
      if (ast->token->at != NULL && ast->token->size >= 0)
      {
        arena_print_cstring(result_arena, CSTRING("'"));
        arena_print_bytes(result_arena, ast->token->size, ast->token->at);
        arena_print_cstring(result_arena, CSTRING("' "));
      }
      else
      {
        arena_print_cstring(result_arena, CSTRING("(ast->token is invalid) "));
      }
      
      if (ast->token->kind != 0)
      {
        arena_print_char64(result_arena, ast->token->kind);
      }
      else
      {
        arena_print_cstring(result_arena, CSTRING("(ast->token->kind == 0)"));
      }
    }
    else
    {
      arena_print_cstring(result_arena, CSTRING("(ast->token == NULL)"));
    }
    
    arena_print_cstring(result_arena, CSTRING(" }  "));
  }
  else
  {
    arena_print_cstring(result_arena, CSTRING("(ast == NULL)  "));
  }
  
  arena_print_cstring(result_arena, CSTRING("\n"));
  
  u64 sub_spaces = spaces + 4;
  
  if (ast != NULL && ast->symbol_by_name != NULL)
  {
    Symbol *symbol = ast->symbol_by_name;
    
    arena_print_row(result_arena, sub_spaces, ' ');
    arena_print_cstring(result_arena, CSTRING("symbol_by_name  "));
    arena_print_bytes(result_arena, symbol->token->size, symbol->token->at);
    arena_print_cstring(result_arena, CSTRING("  "));
    arena_print_cstring(result_arena, symbol->c_name);
    arena_print_cstring(result_arena, CSTRING("\n"));
  }
  
  if (ast != NULL)
  {
    if (ast->scope.symbols != NULL)
    {
      for (s64 i = 0; i < ast->scope.num_symbols; i += 1)
      {
        Symbol *symbol = ast->scope.symbols[i];
        
        arena_print_row(result_arena, sub_spaces, ' ');
        arena_print_cstring(result_arena, CSTRING("symbol ["));
        arena_print_s64(result_arena, i, 10, 2);
        arena_print_cstring(result_arena, CSTRING("]  "));
        arena_print_bytes(result_arena, symbol->token->size, symbol->token->at);
        arena_print_cstring(result_arena, CSTRING("  "));
        arena_print_cstring(result_arena, symbol->c_name);
        arena_print_cstring(result_arena, CSTRING("\n"));
      }
    }
    
    if (ast->expr_0 != NULL) ast_debug_print_recursively(ast->expr_0, sub_spaces, CSTRING("expr_0"), -1, result_arena);
    if (ast->expr_1 != NULL) ast_debug_print_recursively(ast->expr_1, sub_spaces, CSTRING("expr_1"), -1, result_arena);
    if (ast->expr_2 != NULL) ast_debug_print_recursively(ast->expr_2, sub_spaces, CSTRING("expr_2"), -1, result_arena);
    if (ast->stmt_0 != NULL) ast_debug_print_recursively(ast->stmt_0, sub_spaces, CSTRING("stmt_0"), -1, result_arena);
    if (ast->stmt_1 != NULL) ast_debug_print_recursively(ast->stmt_1, sub_spaces, CSTRING("stmt_1"), -1, result_arena);
    
    if (ast->items != NULL)
      for (s64 i = 0; i < ast->num_items; i += 1)
        ast_debug_print_recursively(ast->items[i], sub_spaces, CSTRING("item"), i, result_arena);
  }
}

//

static Symbol *array_find_symbol_by_name(s64 num_symptrs, Symbol **symptrs, s64 name_length, u8 *name)
{
  Symbol *result = NULL;
  
  for (s64 symptr_index = 0; symptr_index < num_symptrs; symptr_index += 1)
  {
    Symbol *symbol = symptrs[symptr_index];
    
    if (symbol->token->size == name_length && memory_equal(name, symbol->token->at, name_length))
    {
      result = symbol;
      break;
    }
  }
  
  return result;
}

static Symbol *scope_find_symbol_by_name(Scope *current_scope, s64 name_length, u8 *name)
{
  Symbol *symbol = NULL;
  
  for (Scope *scope = current_scope; scope != NULL; scope = scope->parent)
  {
    Symbol *s = array_find_symbol_by_name(scope->num_symbols, scope->symbols, name_length, name);
    
    if (s != NULL)
    {
      symbol = s;
      break;
    }
  }
  
  return symbol;
}

//

static Type *type_from_ast(Ast_Node *ast, Scope *current_scope)
{
  debug_assert(ast);
  
  Type *type = NULL;
  u64 ast_kind = ast->kind;
  
  if (ast_kind == CHAR64("u64"))
  {
    arena_push_aligner(keep_arena, alignof(Type));
    type = arena_push(keep_arena, sizeof(Type));
    type->kind = CHAR64("u64");
    type->token = ast->token;
  }
  else if (ast_kind == CHAR64("u8"))
  {
    arena_push_aligner(keep_arena, alignof(Type));
    type = arena_push(keep_arena, sizeof(Type));
    type->kind = CHAR64("u8");
    type->token = ast->token;
  }
  else if (ast_kind == CHAR64("void"))
  {
    arena_push_aligner(keep_arena, alignof(Type));
    type = arena_push(keep_arena, sizeof(Type));
    type->kind = CHAR64("void");
    type->token = ast->token;
  }
  else if (ast_kind == CHAR64("u32"))
  {
    arena_push_aligner(keep_arena, alignof(Type));
    type = arena_push(keep_arena, sizeof(Type));
    type->kind = CHAR64("u32");
    type->token = ast->token;
  }
  else if (ast_kind == CHAR64("s32"))
  {
    arena_push_aligner(keep_arena, alignof(Type));
    type = arena_push(keep_arena, sizeof(Type));
    type->kind = CHAR64("s32");
    type->token = ast->token;
  }
  else if (ast_kind == CHAR64("s64"))
  {
    arena_push_aligner(keep_arena, alignof(Type));
    type = arena_push(keep_arena, sizeof(Type));
    type->kind = CHAR64("s64");
    type->token = ast->token;
  }
  else if (ast_kind == CHAR64("*a"))
  {
    arena_push_aligner(keep_arena, alignof(Type));
    type = arena_push(keep_arena, sizeof(Type));
    type->kind = CHAR64("*a");
    type->token = ast->token;
    type->sub_type = type_from_ast(ast->expr_0, current_scope);
  }
  else if (ast_kind == CHAR64("(a)->b"))
  {
    arena_push_aligner(keep_arena, alignof(Type));
    type = arena_push(keep_arena, sizeof(Type));
    type->kind = CHAR64("(a)->b");
    type->token = ast->token;
    type->sub_type = type_from_ast(ast->expr_0, current_scope);
    
    Arena *temp_arena = get_temp_arena(NULL);
    void *param_types = arena_get_top(temp_arena);
    
    for (s64 i = 0; i < ast->num_items; i += 1)
    {
      Ast_Node *param_ast = ast->items[i];
      
      if (param_ast->kind != CHAR64("a:b"))
        complain(0, param_ast->token, CSTRING("not a declaration"));
      
      Type *param_type = type_from_ast(param_ast->expr_1, current_scope);
      param_type->name_token_opt = param_ast->expr_0->token;
      param_type->c_name_opt = param_ast->expr_0->symbol_by_name->c_name;
      
      arena_push_copy(temp_arena, sizeof(param_type), &param_type);
      type->num_params += 1;
    }
    
    arena_push_aligner(keep_arena, alignof(Type *));
    type->params = arena_push_copy(keep_arena, type->num_params * sizeof(Type *), param_types);
    arena_pop_to_pointer(temp_arena, param_types);
  }
  else if (ast_kind == CHAR64("struct"))
  {
    arena_push_aligner(keep_arena, alignof(Type));
    type = arena_push(keep_arena, sizeof(Type));
    type->kind = CHAR64("struct");
    type->token = ast->token;
    
    debug_assert(ast->struct_c_name != NULL);
    type->struct_c_name = ast->struct_c_name;
    
    Arena *temp_arena = get_temp_arena(NULL);
    void *members_types = arena_get_top(temp_arena);
    
    for (s64 i = 0; i < ast->num_items; i += 1)
    {
      Ast_Node *member_ast = ast->items[i];
      
      if (member_ast->kind != CHAR64("a:b"))
        complain(0, member_ast->token, CSTRING("not a declaration"));
      
      Type *param_type = type_from_ast(member_ast->expr_1, current_scope);
      param_type->name_token_opt = member_ast->expr_0->token;
      param_type->c_name_opt = member_ast->expr_0->symbol_by_name->c_name;
      
      arena_push_copy(temp_arena, sizeof(param_type), &param_type);
      type->num_members += 1;
    }
    
    arena_push_aligner(keep_arena, alignof(Type *));
    type->members = arena_push_copy(keep_arena, type->num_members * sizeof(Type *), members_types);
    arena_pop_to_pointer(temp_arena, members_types);
  }
  else if (ast_kind == CHAR64("name"))
  {
    Symbol *symbol = ast->symbol_by_name;
    
    if (symbol == NULL)
    {
      symbol = scope_find_symbol_by_name(current_scope, ast->token->size, ast->token->at);
      
      if (symbol == NULL)
        complain(0, ast->token, CSTRING("no such symbol"));
      
      ast->symbol_by_name = symbol;
    }
    
    if (symbol->storage != STORAGE_C_TYPEDEF)
      complain(0, ast->token, CSTRING("a valid symbol but not a type"));
    
    if (symbol->type == NULL)
    {
      debug_assert(symbol->ast_node != NULL);
      debug_assert(symbol->ast_node->kind == CHAR64("a:b"));
      
      arena_push_aligner(keep_arena, alignof(Type));
      Type *actual_type = arena_push(keep_arena, sizeof(Type));
      symbol->type = actual_type;
      // NOTE: this prevents it from hitting (symbol->type == NULL) again, allowing recursive type definitions
      // ALSO NOTE: type_size_of and type_alignment_of are not going to be happy about it
      
      Type *copy_type = type_from_ast(symbol->ast_node->expr_1, current_scope);
      *actual_type = *copy_type;
    }
    
    type = symbol->type;
  }
  else
  {
    complain(0, ast->token, CSTRING("not a type"));
  }
  
  debug_assert(type != NULL);
  return type;
}

static u8 *declaration_from_type_and_center(Type *type, u8 *center, Arena *cstring_arena)
{
  u8 *result = NULL;
  u64 type_kind = type->kind;
  
  if (type_kind == CHAR64("u64"))
  {
    result = arena_get_top(cstring_arena);
    arena_print_cstring(cstring_arena, CSTRING("u64 "));
    arena_print_cstring(cstring_arena, center);
    arena_push(cstring_arena, 1);
  }
  else if (type_kind == CHAR64("u8"))
  {
    result = arena_get_top(cstring_arena);
    arena_print_cstring(cstring_arena, CSTRING("u8 "));
    arena_print_cstring(cstring_arena, center);
    arena_push(cstring_arena, 1);
  }
  else if (type_kind == CHAR64("void"))
  {
    result = arena_get_top(cstring_arena);
    arena_print_cstring(cstring_arena, CSTRING("void "));
    arena_print_cstring(cstring_arena, center);
    arena_push(cstring_arena, 1);
  }
  else if (type_kind == CHAR64("u32"))
  {
    result = arena_get_top(cstring_arena);
    arena_print_cstring(cstring_arena, CSTRING("u32 "));
    arena_print_cstring(cstring_arena, center);
    arena_push(cstring_arena, 1);
  }
  else if (type_kind == CHAR64("s32"))
  {
    result = arena_get_top(cstring_arena);
    arena_print_cstring(cstring_arena, CSTRING("s32 "));
    arena_print_cstring(cstring_arena, center);
    arena_push(cstring_arena, 1);
  }
  else if (type_kind == CHAR64("s64"))
  {
    result = arena_get_top(cstring_arena);
    arena_print_cstring(cstring_arena, CSTRING("s64 "));
    arena_print_cstring(cstring_arena, center);
    arena_push(cstring_arena, 1);
  }
  else if (type_kind == CHAR64("*a"))
  {
    u8 *new_center = arena_get_top(cstring_arena);
    arena_print_cstring(cstring_arena, CSTRING("(*"));
    arena_print_cstring(cstring_arena, center);
    arena_print_cstring(cstring_arena, CSTRING(")"));
    arena_push(cstring_arena, 1);
    
    result = declaration_from_type_and_center(type->sub_type, new_center, cstring_arena);
  }
  else if (type_kind == CHAR64("struct"))
  {
    result = arena_get_top(cstring_arena);
    debug_assert(type->struct_c_name != NULL);
    arena_print_cstring(cstring_arena, type->struct_c_name);
    arena_print_cstring(cstring_arena, CSTRING(" "));
    arena_print_cstring(cstring_arena, center);
    arena_push(cstring_arena, 1);
  }
  else if (type_kind == CHAR64("(a)->b"))
  {
    u8 *list = NULL;
    
    for (s64 i = 0; i < type->num_params; i += 1)
    {
      Type *param_type = type->params[i];
      u8 *param_center = CSTRING("");
      
      if (param_type->name_token_opt)
      {
        param_center = arena_get_top(cstring_arena);
        
        debug_assert(param_type->c_name_opt != NULL);
        arena_print_cstring(cstring_arena, param_type->c_name_opt);
        
        if (option_print_actual_names)
        {
          arena_print_cstring(cstring_arena, CSTRING("/*"));
          arena_print_bytes(cstring_arena, param_type->name_token_opt->size, param_type->name_token_opt->at);
          arena_print_cstring(cstring_arena, CSTRING("*/"));
        }
        
        arena_push(cstring_arena, 1);
      }
      
      u8 *param_declaration = declaration_from_type_and_center(param_type, param_center, cstring_arena);
      
      u8 *new_list = arena_get_top(cstring_arena);
      
      if (list)
      {
        arena_print_cstring(cstring_arena, list);
        arena_print_cstring(cstring_arena, CSTRING(", "));
      }
      
      arena_print_cstring(cstring_arena, param_declaration);
      arena_push(cstring_arena, 1);
      
      list = new_list;
    }
    
    u8 *new_center = arena_get_top(cstring_arena);
    arena_print_cstring(cstring_arena, center);
    arena_print_cstring(cstring_arena, CSTRING("("));
    
    if (list)
    {
      arena_print_cstring(cstring_arena, list);
    }
    else
    {
      arena_print_cstring(cstring_arena, CSTRING("void"));
    }
    
    arena_print_cstring(cstring_arena, CSTRING(")"));
    arena_push(cstring_arena, 1);
    
    result = declaration_from_type_and_center(type->sub_type, new_center, cstring_arena);
  }
  else
  {
    complain(0, type->token, CSTRING("can't make the declaration from this"));
  }
  
  debug_assert(result != NULL);
  return result;
}

//

static void scope_append_declarations_from_list(Scope *scope, s64 num_items, Ast_Node **items)
{
  for (s64 i = 0; i < num_items; i += 1)
  {
    Ast_Node *ast = items[i];
    
    if (ast->kind == CHAR64("a:b"))
    {
      Symbol *symbol = ast->expr_0->symbol_by_name;
      debug_assert(symbol != NULL);
      
      Symbol *prev = array_find_symbol_by_name(scope->num_symbols, scope->symbols, symbol->token->size, symbol->token->at);
      
      if (prev != NULL)
      {
        complain(COMPLAIN_ERROR, symbol->token, CSTRING("symbol declared twice in the same scope"));
        complain(COMPLAIN_NOTE, prev->token, CSTRING("here is another declaration"));
        process_exit(1);
      }

      arena_push_copy(keep_arena, sizeof(symbol), &symbol);
      scope->num_symbols += 1; // the symbol is now declared but it is not yet defined
    }
    else if (ast->kind == CHAR64("c_enum"))
    {
      for (s64 ci = 0; ci < ast->num_items; ci += 1)
      {
        Ast_Node *name = ast->items[ci];
        Symbol *symbol = name->symbol_by_name;
        debug_assert(symbol != NULL);
        
        Symbol *prev = array_find_symbol_by_name(scope->num_symbols, scope->symbols, symbol->token->size, symbol->token->at);
      
        if (prev != NULL)
        {
          complain(COMPLAIN_ERROR, symbol->token, CSTRING("symbol declared twice in the same scope"));
          complain(COMPLAIN_NOTE, prev->token, CSTRING("here is another declaration"));
          process_exit(1);
        }
        
        static Type s64_type;
        
        s64_type.kind = CHAR64("s64");
        
        symbol->type = &s64_type;
        symbol->c_enum_value = ci;
        symbol->storage = STORAGE_C_ENUM;

        arena_push_copy(keep_arena, sizeof(symbol), &symbol);
        scope->num_symbols += 1; // the symbol is now declared but it is not yet defined
      }
    }
  }
}

static void scope_define_recursively(Ast_Node *ast, Scope *parent_scope)
{
  u64 ast_kind = ast->kind;
  
  if (ast_kind == CHAR64("root") || ast_kind == CHAR64("stmtlist"))
  {
    Ast_Node *scope_holder = ast;
    arena_push_aligner(keep_arena, alignof(Symbol *));
    scope_holder->scope.symbols = arena_get_top(keep_arena);
    scope_holder->scope.parent = parent_scope;
    
    scope_append_declarations_from_list(&scope_holder->scope, ast->num_items, ast->items);
    
    for (s64 i = 0; i < ast->num_items; i += 1)
    {
      scope_define_recursively(ast->items[i], &scope_holder->scope);
    }
  }
  else if (ast_kind == CHAR64("c_for"))
  {
    Ast_Node *scope_holder = ast;
    arena_push_aligner(keep_arena, alignof(Symbol *));
    scope_holder->scope.symbols = arena_get_top(keep_arena);
    scope_holder->scope.parent = parent_scope;
    
    if (ast->expr_0)
      scope_append_declarations_from_list(&scope_holder->scope, 1, &ast->expr_0);
    
    scope_define_recursively(ast->stmt_0, &scope_holder->scope);
  }
  else if (ast_kind == CHAR64("if-else"))
  {
    scope_define_recursively(ast->stmt_0, parent_scope);
    
    if (ast->stmt_1)
      scope_define_recursively(ast->stmt_1, parent_scope);
  }
  else if (ast_kind == CHAR64("while"))
  {
    scope_define_recursively(ast->stmt_0, parent_scope);
  }
  else if (ast_kind == CHAR64("do-while"))
  {
    scope_define_recursively(ast->stmt_0, parent_scope);
  }
  else if (ast_kind == CHAR64("a:b") && ast->expr_1->kind == CHAR64("(a)->b") && ast->stmt_0 != NULL)
  {
    debug_assert(ast->stmt_0->kind == CHAR64("stmtlist"));
    Ast_Node *scope_holder = ast->stmt_0;
    arena_push_aligner(keep_arena, alignof(Symbol *));
    scope_holder->scope.symbols = arena_get_top(keep_arena);
    scope_holder->scope.parent = parent_scope;
    
    scope_append_declarations_from_list(&scope_holder->scope, ast->expr_1->num_items, ast->expr_1->items);
    scope_append_declarations_from_list(&scope_holder->scope, ast->stmt_0->num_items, ast->stmt_0->items);
    
    for (s64 i = 0; i < ast->stmt_0->num_items; i += 1)
    {
      scope_define_recursively(ast->stmt_0->items[i], &scope_holder->scope);
    }
  }
}

static void ast_debug_print_to_console_error(Ast_Node *ast)
{
  Arena *temp_arena = get_temp_arena(NULL);
  u8 *string = arena_get_top(temp_arena);
  arena_print_cstring(temp_arena, CSTRING("  AST:\n"));
  
  ast_debug_print_recursively(ast, 0, CSTRING("root"), -1, temp_arena);
  
  arena_print_cstring(temp_arena, CSTRING("\n\n"));
  arena_push(temp_arena, 1);
  console_error_print_cstring(string);
  arena_pop_to_pointer(temp_arena, string);
}

static u8 *print_declaration_center_from_symbol(Symbol *symbol, Arena *result_arena)
{
  u8 *center = arena_get_top(result_arena);
  
  arena_print_cstring(result_arena, symbol->c_name);
  
  if (option_print_actual_names)
  {
    arena_print_cstring(result_arena, CSTRING("/*"));
    arena_print_bytes(result_arena, symbol->token->size, symbol->token->at);
    arena_print_cstring(result_arena, CSTRING("*/"));
  }
  
  arena_push(result_arena, 1);
  return center;
}

static Expr_Value rvalue_from(Expr_Value value)
{
  value.is_lvalue = 0;
  return value;
}

static u32 type_is_integer(Type *type)
{
  debug_assert(type != NULL);
  
  u64 the_kind = type->kind;
  
  return the_kind == CHAR64("u64") || the_kind == CHAR64("s64")
      || the_kind == CHAR64("u32") || the_kind == CHAR64("s32")
      || the_kind == CHAR64("u16") || the_kind == CHAR64("s16")
      || the_kind == CHAR64("u8" ) || the_kind == CHAR64("s8" );
}

static s64 type_alignment_of(Type *type)
{
  debug_assert(type != NULL);
  
  u64 the_kind = type->kind;
  
  if (the_kind == CHAR64("*a")) return 8;
  if (the_kind == CHAR64("u64") || the_kind == CHAR64("s64")) return 8;
  if (the_kind == CHAR64("u32") || the_kind == CHAR64("s32")) return 4;
  if (the_kind == CHAR64("u16") || the_kind == CHAR64("s16")) return 2;
  if (the_kind == CHAR64("u8" ) || the_kind == CHAR64("s8" )) return 1;
  
  if (the_kind == CHAR64("struct"))
  {
    s64 struct_alignment = 1;
    
    for (s64 i = 0; i < type->num_members; i += 1)
    {
      Type *member = type->members[i];
      
      s64 member_alignment = type_alignment_of(member);
      
      if (member_alignment > struct_alignment)
        struct_alignment = member_alignment;
    }
    
    return struct_alignment;
  }
  
  if (type->token)
    complain(0, type->token, CSTRING("can't compute type_alignment_of"));
  
  debug_assert(0);
  return 0;
}

static s64 type_size_of(Type *type)
{
  debug_assert(type != NULL);
  
  u64 the_kind = type->kind;
  
  if (the_kind == CHAR64("*a")) return 8;
  if (the_kind == CHAR64("u64") || the_kind == CHAR64("s64")) return 8;
  if (the_kind == CHAR64("u32") || the_kind == CHAR64("s32")) return 4;
  if (the_kind == CHAR64("u16") || the_kind == CHAR64("s16")) return 2;
  if (the_kind == CHAR64("u8" ) || the_kind == CHAR64("s8" )) return 1;
  
  if (the_kind == CHAR64("struct"))
  {
    s64 struct_size = 0;
    s64 struct_alignment = 1;
    
    for (s64 i = 0; i < type->num_members; i += 1)
    {
      Type *member = type->members[i];
      
      s64 member_alignment = type_alignment_of(member);
      
      if (member_alignment > struct_alignment)
        struct_alignment = member_alignment;
      
      struct_size = s64_align(struct_size, member_alignment);
      struct_size += type_size_of(member);
    }
    
    struct_size = s64_align(struct_size, struct_alignment);
    return struct_size;
  }
  
  if (type->token)
    complain(0, type->token, CSTRING("can't compute type_size_of"));
  
  debug_assert(0);
  return 0;
}

static u32 type_equal(Type *a, Type *b)
{
  debug_assert(a);
  debug_assert(b);
  
  if (a == b)
    return 1;
  
  if (a->kind != b->kind)
    return 0;
  
  u64 the_kind = a->kind;
  
  if (type_is_integer(a) || the_kind == CHAR64("void"))
  {
    return 1;
  }
  else if (the_kind == CHAR64("*a"))
  {
    return type_equal(a->sub_type, b->sub_type);
  }
  else if (the_kind == CHAR64("(a)->b"))
  {
    if (!type_equal(a->sub_type, b->sub_type))
      return 0;
    
    if (a->num_params != b->num_params)
      return 0;
    
    s64 num_params = a->num_params;
    
    for (s64 i = 0; i < num_params; i += 1)
      if (!type_equal(a->params[i], b->params[i]))
        return 0;
  }
  else if (the_kind == CHAR64("struct"))
  {
    return (a->struct_c_name == b->struct_c_name);
  }
  else
  {
    debug_assert(0 && "in type_equal");
  }
  
  return 1;
}

static u32 type_implicit_cast_is_possible(Type *dst, Type *src)
{
  debug_assert(dst != NULL);
  debug_assert(src != NULL);
  
  if (type_is_integer(dst) && type_is_integer(src))
  {
    return 1;
  }
  else if (dst->kind == src->kind)
  {
    u64 the_kind = src->kind;
    
    if (the_kind == CHAR64("void"))
    {
      return 1;
    }
    else if (the_kind == CHAR64("*a"))
    {
      if (src->sub_type->kind == CHAR64("void") || dst->sub_type->kind == CHAR64("void"))
        return 1;
      
      return type_equal(src->sub_type, dst->sub_type);
    }
    else if (the_kind == CHAR64("struct"))
    {
      return dst == src;
    }
    else
    {
      if (dst->token)
        complain(0, dst->token, CSTRING("can't check if type_implicit_cast_is_possible"));
      
      if (src->token)
        complain(0, src->token, CSTRING("can't check if type_implicit_cast_is_possible"));
      
      debug_assert(0);
    }
  }
  else
  {
    return 0;
  }
  
  return 0;
}

static u32 type_explicit_cast_is_possible(Type *dst, Type *src)
{
  (void) src;
  
  if (dst->kind == CHAR64("(a)->b"))
    return 0;
  
  return 1;
}

static s64 bytes_from_extended_text(s64 length, u8 *text, Arena *result_arena)
{
  s64 size = 0;
  
  for (s64 ti = 0; ti < length; ti += 1)
  {
    u8 byte_value = 0;
    
    if (text[ti] == '\\')
    {
      ti += 1;
      debug_assert(ti < length);
      
      /**/ if (text[ti] == '\\') byte_value = '\\';
      else if (text[ti] == '"')  byte_value = '"';
      else if (text[ti] == '\'') byte_value = '\'';
      else if (text[ti] == '`')  byte_value = '`';
      else if (text[ti] == 'n')  byte_value = '\n';
      else
      {
        debug_assert(ascii_is_uppercase_hexadecimal_digit(text[ti]));
        
        u32 d0 = 0;
        u32 d1 = 0;
        
        if (ti + 1 < length && ascii_is_uppercase_hexadecimal_digit(text[ti + 1]))
        {
          d0 = ascii_digit_to_int(text[ti + 0]);
          d1 = ascii_digit_to_int(text[ti + 1]);
          ti += 1;
        }
        else
        {
          d1 = ascii_digit_to_int(text[ti + 0]);
        }
        
        debug_assert(d0 < 16);
        debug_assert(d1 < 16);
        byte_value = (d0 << 4) | (d1);
      }
    }
    else
    {
      byte_value = text[ti];
    }
    
    arena_push_copy(result_arena, sizeof(byte_value), &byte_value);
    size += 1;
  }
  
  return size;
}

static Expr_Value fe_compile_expression_recursively(Ast_Node *expr, Scope *current_scope)
{
  debug_assert(expr != NULL);
  debug_assert(current_scope != NULL);
  
  Expr_Value result = {0};
  
  u64 expr_kind = expr->kind;
  
  /**/ if (expr_kind == CHAR64("name"))
  {
    Symbol *symbol = expr->symbol_by_name;
    
    if (symbol == NULL)
    {
      symbol = scope_find_symbol_by_name(current_scope, expr->token->size, expr->token->at);
      
      if (symbol == NULL)
        complain(0, expr->token, CSTRING("no such symbol"));
      
      expr->symbol_by_name = symbol;
    }
    
    if (symbol->storage == STORAGE_LOCAL && !symbol->local_is_active)
    {
      complain(COMPLAIN_ERROR, expr->token, CSTRING("using a local variable before it's declared"));
      complain(COMPLAIN_NOTE, symbol->token, CSTRING("the declaration is here"));
      process_exit(1);
    }
    
    if (symbol->type == NULL)
      complain(0, expr->token, CSTRING("symbol->type == NULL"));
    
    debug_assert(symbol->type != NULL);
    result.type = symbol->type;
    result.token = expr->token;
    symbol->num_uses += 1;
    
    if (symbol->storage != STORAGE_C_ENUM)
    {
      result.is_lvalue = (symbol->type->kind != CHAR64("(a)->b"));
    }
    else
    {
      result.is_constexpr = 1;
      result.as_u64 = symbol->c_enum_value;
    }
  }
  else if (expr_kind == CHAR64("null"))
  {
    static Type void_type;
    static Type ptr_to_void_type;
    
    void_type.kind = CHAR64("void");
    
    ptr_to_void_type.kind = CHAR64("*a");
    ptr_to_void_type.sub_type = &void_type;
    
    result.type = &ptr_to_void_type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("c_string"))
  {
    static Type u8_type;
    static Type ptr_to_u8_type;
    
    u8_type.kind = CHAR64("u8");
    
    ptr_to_u8_type.kind = CHAR64("*a");
    ptr_to_u8_type.sub_type = &u8_type;
    
    result.type = &ptr_to_u8_type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("'"))
  {
    static Type u64_type;
    
    u64_type.kind = CHAR64("u64");
    
    result.type = &u64_type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("integer"))
  {
    u64 value = 0;
    u64 base = 10;
    
    s64 size = expr->token->size;
    u8 *text = expr->token->at;
    
    /**/ if (size > 2 && text[0] == '0' && text[1] == 'x')
    {
      text += 2;
      size -= 2;
      base = 16;
    }
    else if (size > 2 && text[0] == '0' && text[1] == 'b')
    {
      text += 2;
      size -= 2;
      base = 2;
    }
    else if (size > 2 && text[0] == '0' && text[1] == 'o')
    {
      text += 2;
      size -= 2;
      base = 8;
    }
    else if (size > 2 && text[0] == '0' && text[1] == 'd')
    {
      text += 2;
      size -= 2;
      base = 10;
    }
    
    for (s64 i = 0; i < size; i += 1)
    {
      u32 ascii_digit = text[i];
      
      if (ascii_digit != '_')
      {
        u64 digit_int = ascii_digit_to_int(ascii_digit);
        
        if (digit_int >= base)
          complain(0, expr->token, CSTRING("bad integer constant"));
      
        value *= base;
        value += digit_int;
      }
    }
    
    static Type u64_type;
    
    u64_type.kind = CHAR64("u64");
    
    result.type = &u64_type;
    result.token = expr->token;
    result.is_constexpr = 1;
    result.as_u64 = value;
  }
  else if (expr_kind == CHAR64("size_of"))
  {
    Type *type = type_from_ast(expr->expr_0, current_scope);
    
    static Type s64_type;
    
    s64_type.kind = CHAR64("s64");
    
    result.type = &s64_type;
    result.token = expr->token;
    result.is_constexpr = 1;
    result.as_u64 = type_size_of(type);
  }
  else if (expr_kind == CHAR64("align_of"))
  {
    Type *type = type_from_ast(expr->expr_0, current_scope);
    
    static Type s64_type;
    
    s64_type.kind = CHAR64("s64");
    
    result.type = &s64_type;
    result.token = expr->token;
    result.is_constexpr = 1;
    result.as_u64 = type_alignment_of(type);
  }
  else if (expr_kind == CHAR64("c_dbgpos"))
  {
    static Type u8_type;
    static Type ptr_to_u8_type;
    
    u8_type.kind = CHAR64("u8");
    
    ptr_to_u8_type.kind = CHAR64("*a");
    ptr_to_u8_type.sub_type = &u8_type;
    
    result.type = &ptr_to_u8_type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a(b)"))
  {
    Expr_Value function_value = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    
    Type *function_type = function_value.type;
    
    if (function_type->kind == CHAR64("*a"))
      function_type = function_type->sub_type;
    
    if (function_type->kind != CHAR64("(a)->b"))
      complain(0, function_value.token, CSTRING("not a function"));
    
    if (expr->num_items < function_type->num_params)
      complain(0, expr->token, CSTRING("not enough arguments"));

    if (expr->num_items > function_type->num_params)
      complain(0, expr->token, CSTRING("too many arguments"));
    
    for (s64 i = 0; i < expr->num_items; i += 1)
    {
      Ast_Node *arg = expr->items[i];
      
      Expr_Value arg_value = rvalue_from(fe_compile_expression_recursively(arg, current_scope));
      
      Type *param_type = function_type->params[i];
      
      if (!type_implicit_cast_is_possible(param_type, arg_value.type))
        complain(0, arg_value.token, CSTRING("the argument type doesn't match the parameter type"));
    }
    
    result.type = function_type->sub_type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a=b"))
  {
    Expr_Value lvalue =             fe_compile_expression_recursively(expr->expr_0, current_scope);
    Expr_Value rvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_1, current_scope));
    
    if (!lvalue.is_lvalue)
      complain(0, lvalue.token, CSTRING("need an lvalue on the left of the assignment operator"));
    
    if (!type_implicit_cast_is_possible(lvalue.type, rvalue.type))
      complain(0, rvalue.token, CSTRING("the value can't be implicitly cast to the type on the left of the assignment"));
    
    result.type = lvalue.type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a*=b") || expr_kind == CHAR64("a/=b") || expr_kind == CHAR64("a%=b"))
  {
    Expr_Value lvalue =             fe_compile_expression_recursively(expr->expr_0, current_scope);
    Expr_Value rvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_1, current_scope));
    
    if (!lvalue.is_lvalue)
      complain(0, lvalue.token, CSTRING("need an lvalue on the left of the assignment operator"));
    
    if ( !(type_is_integer(lvalue.type) && type_is_integer(rvalue.type)) )
      complain(0, rvalue.token, CSTRING("the value can't be implicitly cast to the type on the left of the assignment"));
    
    result.type = lvalue.type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a+=b"))
  {
    Expr_Value lvalue =             fe_compile_expression_recursively(expr->expr_0, current_scope);
    Expr_Value rvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_1, current_scope));
    
    if (!lvalue.is_lvalue)
      complain(0, lvalue.token, CSTRING("need an lvalue on the left of the assignment operator"));
    
    if (type_is_integer(lvalue.type) && type_is_integer(rvalue.type))
    {

    }
    else if (lvalue.type->kind == CHAR64("*a") && type_is_integer(rvalue.type))
    {
      if (lvalue.type->sub_type->kind == CHAR64("void") && lvalue.type->sub_type->kind == CHAR64("(a)->b"))
        complain(0, expr->token, CSTRING("can't do pointer arithmetics with that kind of pointer"));
    }
    else 
    {
      complain(0, rvalue.token, CSTRING("the value can't be implicitly cast to the type of the left part of the assignment"));
    }
    
    result.type = lvalue.type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a-=b"))
  {
    Expr_Value lvalue =             fe_compile_expression_recursively(expr->expr_0, current_scope);
    Expr_Value rvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_1, current_scope));
    
    if (!lvalue.is_lvalue)
      complain(0, lvalue.token, CSTRING("need an lvalue on the left of the assignment operator"));
    
    if (type_is_integer(lvalue.type) && type_is_integer(rvalue.type))
    {

    }
    else if (lvalue.type->kind == CHAR64("*a") && type_is_integer(rvalue.type))
    {
      if (lvalue.type->sub_type->kind == CHAR64("void") && lvalue.type->sub_type->kind == CHAR64("(a)->b"))
        complain(0, expr->token, CSTRING("can't do pointer arithmetics with that kind of pointer"));
    }
    else 
    {
      complain(0, rvalue.token, CSTRING("the value can't be implicitly cast to the type of the left part of the assignment"));
    }
    
    result.type = lvalue.type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a+b"))
  {
    Expr_Value lvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    Expr_Value rvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_1, current_scope));
    
    if (type_is_integer(lvalue.type) && type_is_integer(rvalue.type))
    {
      s64 lsize = type_size_of(lvalue.type);
      s64 rsize = type_size_of(rvalue.type);
      
      result.type = (lsize > rsize) ? lvalue.type : rvalue.type;
    }
    else if (rvalue.type->kind == CHAR64("*a") && type_is_integer(lvalue.type))
    {
      if (rvalue.type->sub_type->kind == CHAR64("void") && rvalue.type->sub_type->kind == CHAR64("(a)->b"))
        complain(0, expr->token, CSTRING("can't do pointer arithmetics with that kind of pointer"));
      
      result.type = rvalue.type;
    }
    else if (lvalue.type->kind == CHAR64("*a") && type_is_integer(rvalue.type))
    {
      if (lvalue.type->sub_type->kind == CHAR64("void") && lvalue.type->sub_type->kind == CHAR64("(a)->b"))
        complain(0, expr->token, CSTRING("can't do pointer arithmetics with that kind of pointer"));
      
      result.type = lvalue.type;
    }
    else if (lvalue.type->kind == CHAR64("*a") && rvalue.type->kind == CHAR64("*a"))
    {
      complain(0, expr->token, CSTRING("pointer plus pointer makes no sense"));
    }
    else
    {
      complain(0, rvalue.token, CSTRING("the value can't be implicitly cast to the type of the left part of the assignment"));
    }
    
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a-b"))
  {
    Expr_Value lvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    Expr_Value rvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_1, current_scope));
    
    if (type_is_integer(lvalue.type) && type_is_integer(rvalue.type))
    {
      s64 lsize = type_size_of(lvalue.type);
      s64 rsize = type_size_of(rvalue.type);
      
      result.type = (lsize > rsize) ? lvalue.type : rvalue.type;
    }
    else if (lvalue.type->kind == CHAR64("*a") && type_is_integer(rvalue.type))
    {
      if (lvalue.type->sub_type->kind == CHAR64("void") && lvalue.type->sub_type->kind == CHAR64("(a)->b"))
        complain(0, expr->token, CSTRING("can't do pointer arithmetics with that kind of pointer"));
      
      result.type = lvalue.type;
    }
    else if (lvalue.type->kind == CHAR64("*a") && rvalue.type->kind == CHAR64("*a"))
    {
      if (!type_equal(lvalue.type->sub_type, rvalue.type->sub_type))
        complain(0, expr->token, CSTRING("can't subtract pointers of different types"));
      
      static Type s64_type;
      
      s64_type.kind = CHAR64("s64");
      
      result.type = &s64_type;
    }
    else
    {
      complain(0, rvalue.token, CSTRING("the value can't be implicitly cast to the type of the left part of the assignment"));
    }
    
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a*b") || expr_kind == CHAR64("a/b") || expr_kind == CHAR64("a%b"))
  {
    Expr_Value lvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    Expr_Value rvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_1, current_scope));
    
    if (!type_is_integer(lvalue.type))
      complain(0, lvalue.token, CSTRING("numeric operators only work with integer types at the moment"));
    
    if (!type_is_integer(rvalue.type))
      complain(0, rvalue.token, CSTRING("numeric operators only work with integer types at the moment"));
    
    s64 lsize = type_size_of(lvalue.type);
    s64 rsize = type_size_of(rvalue.type);
    
    result.type = (lsize > rsize) ? lvalue.type : rvalue.type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a|b") || expr_kind == CHAR64("a&b") || expr_kind == CHAR64("a^b"))
  {
    Expr_Value lvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    Expr_Value rvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_1, current_scope));
    
    if (!type_is_integer(lvalue.type))
      complain(0, lvalue.token, CSTRING("bitwise operators only work with integer types"));
    
    if (!type_is_integer(rvalue.type))
      complain(0, rvalue.token, CSTRING("bitwise operators only work with integer types"));
    
    s64 lsize = type_size_of(lvalue.type);
    s64 rsize = type_size_of(rvalue.type);
    
    result.type = (lsize > rsize) ? lvalue.type : rvalue.type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a<<b") || expr_kind == CHAR64("a>>b"))
  {
    Expr_Value lvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    Expr_Value rvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_1, current_scope));
    
    if (!type_is_integer(lvalue.type))
      complain(0, lvalue.token, CSTRING("bitwise operators only work with integer types"));
    
    if (!type_is_integer(rvalue.type))
      complain(0, rvalue.token, CSTRING("bitwise operators only work with integer types"));

    result.type = lvalue.type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a==b") || expr_kind == CHAR64("a!=b")
        || expr_kind == CHAR64("a<=b") || expr_kind == CHAR64("a>=b")
        || expr_kind == CHAR64("a<b" ) || expr_kind == CHAR64("a>b" ))
  {
    Expr_Value lvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    Expr_Value rvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_1, current_scope));
    
    if (!type_implicit_cast_is_possible(lvalue.type, rvalue.type))
      complain(0, expr->token, CSTRING("can't compare this"));
    
    static Type u32_type;
    
    u32_type.kind = CHAR64("u32");
    
    result.type = &u32_type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a or b") || expr_kind == CHAR64("a and b"))
  {
    Expr_Value lvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    Expr_Value rvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_1, current_scope));
    
    (void) lvalue;
    (void) rvalue;
    
    static Type u32_type;
    
    u32_type.kind = CHAR64("u64");
    
    result.type = &u32_type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("not a"))
  {
    Expr_Value sub_value = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    (void) sub_value;
    
    static Type u32_type;
    
    u32_type.kind = CHAR64("u64");
    
    result.type = &u32_type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("^a"))
  {
    Expr_Value sub_value = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    
    if (!type_is_integer(sub_value.type))
      complain(0, expr->token, CSTRING("the betwise NOT operator only works with integers"));
    
    result.type = sub_value.type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("-a") || expr_kind == CHAR64("+a"))
  {
    Expr_Value sub_value = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    
    if (!type_is_integer(sub_value.type))
      complain(0, expr->token, CSTRING("numeric unary operators only works with integers at the moment"));
    
    result.type = sub_value.type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a.&"))
  {
    debug_assert(expr->expr_0 != NULL);
    
    Expr_Value lvalue = fe_compile_expression_recursively(expr->expr_0, current_scope);
    
    if (!lvalue.is_lvalue)
      complain(0, lvalue.token, CSTRING("need an lvalue on the left of the take-pointer operator"));
    
    arena_push_aligner(keep_arena, alignof(Type));
    Type *ptr_to_lvalue_type = arena_push(keep_arena, sizeof(Type));
    
    ptr_to_lvalue_type->kind = CHAR64("*a");
    ptr_to_lvalue_type->token = expr->token;
    ptr_to_lvalue_type->sub_type = lvalue.type;
    
    result.type = ptr_to_lvalue_type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a.*"))
  {
    debug_assert(expr->expr_0 != NULL);
    
    Expr_Value lvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    
    if (lvalue.type->kind != CHAR64("*a"))
      complain(0, lvalue.token, CSTRING("need a pointer to get the value by pointer"));
    
    result.type = lvalue.type->sub_type;
    result.is_lvalue = 1;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a[b]"))
  {
    Expr_Value lvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    Expr_Value rvalue = rvalue_from(fe_compile_expression_recursively(expr->expr_1, current_scope));
    
    if (lvalue.type->kind != CHAR64("*a"))
      complain(0, lvalue.token, CSTRING("need a pointer to get the value by pointer"));
    
    if (!type_is_integer(rvalue.type))
      complain(0, rvalue.token, CSTRING("the index must be of an integer type"));
    
    result.type = lvalue.type->sub_type;
    result.is_lvalue = 1;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("cast"))
  {
    Expr_Value value = rvalue_from(fe_compile_expression_recursively(expr->expr_0, current_scope));
    Type *type = type_from_ast(expr->expr_1, current_scope);
    
    if (!type_explicit_cast_is_possible(type, value.type))
      complain(0, expr->token, CSTRING("can't do this cast"));
    
    result.type = type;
    result.token = expr->token;
  }
  else if (expr_kind == CHAR64("a.b"))
  {
    Expr_Value lvalue_struct_or_rvalue_ptr_to_struct = fe_compile_expression_recursively(expr->expr_0, current_scope);
    
    Type *struct_type = NULL;
    
    if (lvalue_struct_or_rvalue_ptr_to_struct.type->kind == CHAR64("struct"))
    {
      if (!lvalue_struct_or_rvalue_ptr_to_struct.is_lvalue)
        complain(0, expr->token, CSTRING("struct is NOT lvalue"));
      
      struct_type = lvalue_struct_or_rvalue_ptr_to_struct.type;
    }
    else if (lvalue_struct_or_rvalue_ptr_to_struct.type->kind == CHAR64("*a"))
    {
      struct_type = lvalue_struct_or_rvalue_ptr_to_struct.type->sub_type;
      
      if (struct_type->kind != CHAR64("struct"))
        complain(0, expr->token, CSTRING("not a pointer to struct"));
    }
    else
    {
      complain(0, expr->token, CSTRING("not a struct, not a pointer to struct"));
    }
    
    debug_assert(struct_type != NULL);
    debug_assert(struct_type->kind == CHAR64("struct"));
    
    if (expr->expr_1->kind != CHAR64("name"))
      complain(0, expr->token, CSTRING("expected a name of a member"));
    
    Token *name = expr->expr_1->token;
    Type *member_type = NULL;
    
    for (s64 i = 0; i < struct_type->num_members; i += 1)
    {
      Type *ith_member_type = struct_type->members[i];
      debug_assert(ith_member_type->name_token_opt != NULL);
      Token *member_name = ith_member_type->name_token_opt;
      
      if (member_name->size == name->size && memory_equal(member_name->at, name->at, name->size))
      {
        member_type = ith_member_type;
        break;
      }
    }
    
    if (member_type == NULL)
      complain(0, expr->expr_1->token, CSTRING("not a member of the struct"));
    
    result.type = member_type;
    result.is_lvalue = 1;
    result.token = expr->token;
  }
  else
  {
    complain(0, expr->token, CSTRING("iduno how to PRE-compile this"));
  }
  
  debug_assert(result.type != NULL);
  debug_assert(result.token != NULL);
  expr->value = result;
  return result;
}

static void fe_compile_statement_recursively(Ast_Node *stmt, Scope *current_scope, Symbol *current_function_symbol)
{
  u64 stmt_kind = stmt->kind;
  
  if (stmt_kind == CHAR64("root"))
  {
    Ast_Node *root = stmt;
    
    for (s64 i = 0; i < root->num_items; i += 1)
    {
      Ast_Node *ast = root->items[i];
      
      if (ast->kind == CHAR64("a:b"))
      {
        Symbol *symbol = ast->expr_0->symbol_by_name;
        
        debug_assert(symbol->storage == STORAGE_UNDEFINED);
        
        /**/ if (symbol->c_typedef != NULL) symbol->storage = STORAGE_C_TYPEDEF;
        else if (symbol->c_extern  != NULL) symbol->storage = STORAGE_EXTERN;
        else                                symbol->storage = STORAGE_STATIC;
        
        if (symbol->type == NULL)
          symbol->type = type_from_ast(ast->expr_1, &root->scope);
      }
    }
    
    for (s64 i = 0; i < root->num_items; i += 1)
    {
      fe_compile_statement_recursively(root->items[i], &root->scope, NULL);
    }
  }
  else if (stmt_kind == CHAR64("stmtlist"))
  {
    Ast_Node *list = stmt;
    
    for (s64 i = 0; i < list->num_items; i += 1)
    {
      Ast_Node *ast = list->items[i];
      
      if (ast->kind == CHAR64("a:b"))
      {
        Symbol *symbol = ast->expr_0->symbol_by_name;
        
        debug_assert(symbol->storage == STORAGE_UNDEFINED);
        
        /**/ if (symbol->c_typedef != NULL             ) symbol->storage = STORAGE_C_TYPEDEF;
        else if (symbol->c_extern  != NULL             ) symbol->storage = STORAGE_EXTERN;
        else if (ast->expr_1->kind == CHAR64("(a)->b"))  symbol->storage = STORAGE_STATIC;
        else                                             symbol->storage = STORAGE_LOCAL;
        
        if (symbol->type == NULL)
          symbol->type = type_from_ast(ast->expr_1, &list->scope);
      }
    }
    
    for (s64 i = 0; i < list->num_items; i += 1)
    {
      fe_compile_statement_recursively(list->items[i], &list->scope, current_function_symbol);
    }
  }
  else if (stmt_kind == CHAR64("c_for"))
  {
    if (stmt->expr_0)
    {
      Ast_Node *decl = stmt->expr_0;
      debug_assert(decl->kind == CHAR64("a:b"));
      
      Symbol *symbol = decl->expr_0->symbol_by_name;
      
      debug_assert(symbol->storage == STORAGE_UNDEFINED);
      
      error_assert(symbol->c_typedef == NULL);
      error_assert(symbol->c_extern == NULL);
      error_assert(stmt->expr_0->kind != CHAR64("(a)->b"));
      
      symbol->storage = STORAGE_LOCAL;
      symbol->local_is_active = 1;
      
      if (symbol->type == NULL)
        symbol->type = type_from_ast(decl->expr_1, &stmt->scope);
    }
    
    if (stmt->expr_1) fe_compile_expression_recursively(stmt->expr_1, &stmt->scope);
    if (stmt->expr_2) fe_compile_expression_recursively(stmt->expr_2, &stmt->scope);
    
    fe_compile_statement_recursively(stmt->stmt_0, &stmt->scope, current_function_symbol);
  }
  else if (stmt_kind == CHAR64("c_enum"))
  {
    // do nothing?
  }
  else if (stmt_kind == CHAR64("break"))
  {
    // do nothing!
  }
  else if (stmt_kind == CHAR64("continue"))
  {
    // do nothing...
  }
  else if (stmt_kind == CHAR64("if-else"))
  {
    fe_compile_expression_recursively(stmt->expr_0, current_scope);
    fe_compile_statement_recursively(stmt->stmt_0, current_scope, current_function_symbol);
    
    if (stmt->stmt_1)
      fe_compile_statement_recursively(stmt->stmt_1, current_scope, current_function_symbol);
  }
  else if (stmt_kind == CHAR64("while"))
  {
    fe_compile_expression_recursively(stmt->expr_0, current_scope);
    fe_compile_statement_recursively(stmt->stmt_0, current_scope, current_function_symbol);
  }
  else if (stmt_kind == CHAR64("do-while"))
  {
    fe_compile_statement_recursively(stmt->stmt_0, current_scope, current_function_symbol);
    fe_compile_expression_recursively(stmt->expr_0, current_scope);
  }
  else if (stmt_kind == CHAR64("return"))
  {
    debug_assert(current_function_symbol);
    debug_assert(current_function_symbol->type);
    debug_assert(current_function_symbol->type->sub_type);
    
    if (stmt->expr_0)
    {
      Expr_Value rvalue = rvalue_from(fe_compile_expression_recursively(stmt->expr_0, current_scope));
      
      if (!type_implicit_cast_is_possible(current_function_symbol->type->sub_type, rvalue.type))
        complain(0, rvalue.token, CSTRING("the value can't be implicitly cast to the return type"));
    }
  }
  else if (stmt_kind == CHAR64("a:b") && stmt->expr_1->kind == CHAR64("(a)->b") && stmt->stmt_0 != NULL)
  {
    Ast_Node *func = stmt;
    
    Symbol *function_symbol = func->expr_0->symbol_by_name;
    debug_assert(function_symbol);
    
    for (s64 i = 0; i < func->expr_1->num_items; i += 1)
    {
      Ast_Node *ast = func->expr_1->items[i];
      
      debug_assert(ast->kind == CHAR64("a:b"));
      
      Symbol *symbol = ast->expr_0->symbol_by_name;
      
      debug_assert(symbol->storage == STORAGE_UNDEFINED);
      
      symbol->storage = STORAGE_LOCAL;
      symbol->local_is_active = 1;
      
      if (symbol->type == NULL)
        symbol->type = type_from_ast(ast->expr_1, current_scope);
    }
    
    fe_compile_statement_recursively(func->stmt_0, current_scope, function_symbol);
  }
  else if (stmt_kind == CHAR64("a:b"))
  {
    Symbol *symbol = stmt->expr_0->symbol_by_name;
    
    if (symbol->storage == STORAGE_LOCAL)
      symbol->local_is_active = 1;
  }
  else
  {
    fe_compile_expression_recursively(stmt, current_scope);
  }
}

static Ast_Node *language_frontend(u8 *input_path)
{
  // read the input file:
  u8 *input_text = NULL;
  {
    input_text = file_read_all_bytes(input_path, keep_arena);
    error_assert(input_text != NULL);
    arena_push(keep_arena, 1);
  }
  
  // print the input file
  if (0)
  {
    console_error_print_cstring(CSTRING("  FILE:\n"));
    console_error_print_cstring(input_text);
    console_error_print_cstring(CSTRING("\n"));
  }
  
  // read all tokens:
  Token *input_tokens = NULL;
  s64 num_input_tokens = 0;
  {
    arena_push_aligner(keep_arena, alignof(Token));
    input_tokens = arena_get_top(keep_arena);
    
    u8 *cp = input_text;
    
    for (;;)
    {
      // skip spaces and comments
      for (;;)
      {
        while (ascii_is_space(*cp))
          cp += 1;
        
        if (cp[0] == '/' && cp[1] == '/')
        {
          while (*cp != '\0' && *cp != '\n')
            cp += 1;
        }
        else
        {
          break;
        }
      }
      
      u8 *token_beg = cp;
      u64 token_kind = 0;
      
      /**/ if (*cp == '\0')
      {
        break;
      }
      else if (ascii_is_decimal_digit(*cp))
      {
        token_kind = CHAR64("integer");
        cp += 1;
        
        while (ascii_is_letter_or_digit(*cp) || *cp == '_')
        {
          cp += 1;
        }
      }
      else if (ascii_is_letter(*cp) || *cp == '_')
      {
        token_kind = CHAR64("name");
        cp += 1;
        
        while (ascii_is_letter_or_digit(*cp) || *cp == '_')
        {
          cp += 1;
        }
        
        s64 size = cp - token_beg;
        
        /**/ if (size == 2)
        {
          /**/ if (memory_equal(token_beg, CSTRING("u8"), size)) token_kind = CHAR64("u8");
          else if (memory_equal(token_beg, CSTRING("s8"), size)) token_kind = CHAR64("s8");
          else if (memory_equal(token_beg, CSTRING("or"), size)) token_kind = CHAR64("or");
          else if (memory_equal(token_beg, CSTRING("if"), size)) token_kind = CHAR64("if");
          else if (memory_equal(token_beg, CSTRING("do"), size)) token_kind = CHAR64("do");
        }
        else if (size == 3)
        {
          /**/ if (memory_equal(token_beg, CSTRING("u64"), size)) token_kind = CHAR64("u64");
          else if (memory_equal(token_beg, CSTRING("u32"), size)) token_kind = CHAR64("u32");
          else if (memory_equal(token_beg, CSTRING("u16"), size)) token_kind = CHAR64("u16");
          else if (memory_equal(token_beg, CSTRING("s64"), size)) token_kind = CHAR64("s64");
          else if (memory_equal(token_beg, CSTRING("s32"), size)) token_kind = CHAR64("s32");
          else if (memory_equal(token_beg, CSTRING("s16"), size)) token_kind = CHAR64("s16");
          else if (memory_equal(token_beg, CSTRING("f64"), size)) token_kind = CHAR64("f64");
          else if (memory_equal(token_beg, CSTRING("f32"), size)) token_kind = CHAR64("f32");
          else if (memory_equal(token_beg, CSTRING("and"), size)) token_kind = CHAR64("and");
          else if (memory_equal(token_beg, CSTRING("not"), size)) token_kind = CHAR64("not");
        }
        else if (size == 4)
        {
          /**/ if (memory_equal(token_beg, CSTRING("void"), size)) token_kind = CHAR64("void");
          else if (memory_equal(token_beg, CSTRING("null"), size)) token_kind = CHAR64("null");
          else if (memory_equal(token_beg, CSTRING("else"), size)) token_kind = CHAR64("else");
          else if (memory_equal(token_beg, CSTRING("enum"), size)) token_kind = CHAR64("enum");
          else if (memory_equal(token_beg, CSTRING("cast"), size)) token_kind = CHAR64("cast");
        }
        else if (size == 5)
        {
          /**/ if (memory_equal(token_beg, CSTRING("while"), size)) token_kind = CHAR64("while");
          else if (memory_equal(token_beg, CSTRING("break"), size)) token_kind = CHAR64("break");
          else if (memory_equal(token_beg, CSTRING("unoin"), size)) token_kind = CHAR64("unoin");
          else if (memory_equal(token_beg, CSTRING("c_for"), size)) token_kind = CHAR64("c_for");
        }
        else if (size == 6)
        {
          /**/ if (memory_equal(token_beg, CSTRING("return"), size)) token_kind = CHAR64("return");
          else if (memory_equal(token_beg, CSTRING("c_name"), size)) token_kind = CHAR64("c_name");
          else if (memory_equal(token_beg, CSTRING("struct"), size)) token_kind = CHAR64("struct");
          else if (memory_equal(token_beg, CSTRING("c_load"), size)) token_kind = CHAR64("c_load");
          else if (memory_equal(token_beg, CSTRING("c_enum"), size)) token_kind = CHAR64("c_enum");
        }
        else if (size == 7)
        {
          /**/ if (memory_equal(token_beg, CSTRING("size_of"), size)) token_kind = CHAR64("size_of");
          else if (memory_equal(token_beg, CSTRING("type_of"), size)) token_kind = CHAR64("type_of");
        }
        else if (size == 8)
        {
          /**/ if (memory_equal(token_beg, CSTRING("c_extern"), size)) token_kind = CHAR64("c_extern");
          else if (memory_equal(token_beg, CSTRING("c_string"), size)) token_kind = CHAR64("c_string");
          else if (memory_equal(token_beg, CSTRING("continue"), size)) token_kind = CHAR64("continue");
          else if (memory_equal(token_beg, CSTRING("c_dbgpos"), size)) token_kind = CHAR64("c_dbgpos");
        }
        else if (size == 9)
        {
          if (memory_equal(token_beg, CSTRING("c_typedef"), size)) token_kind = CHAR64("ctypedef");
        }
        else if (size == 12)
        {
          if (memory_equal(token_beg, CSTRING("alignment_of"), size)) token_kind = CHAR64("align_of");
        }
      }
      else if (*cp == '"' || *cp == '\'' || *cp == '`')
      {
        token_kind = (*cp == '`') ? CHAR64("name") : *cp;
        u32 end_quote = *cp;
        cp += 1;
        s64 num_backslashes = 0;
        
        while (!(*cp == end_quote && num_backslashes % 2 == 0))
        {
          error_assert(*cp != '\0');
          error_assert(*cp != '\n');
          
          for (num_backslashes = 0; *cp == '\\'; num_backslashes += 1)
          {
            cp += 1;
          }
          
          if (num_backslashes == 0)
          {
            cp += 1;
          }
        }
        
        cp += 1;
      }
      else if (cp[0] == '-' && cp[1] == '>')
      {
        token_kind = CHAR64("->");
        cp += 2;
      }
      else
      {
        u32 c0 = cp[0];
        u32 c1 = cp[1];
        u32 c2 = cp[2];
        
        s64 size = 0;
        
        /**/ if (c0 == '<' && c1 == '<' && c2 == '=') { size = 3; token_kind = CHAR64("<<="); }
        else if (c0 == '>' && c1 == '>' && c2 == '=') { size = 3; token_kind = CHAR64(">>="); }
        else if (c0 == '+' && c1 == '=') { size = 2; token_kind = CHAR64("+="); }
        else if (c0 == '-' && c1 == '=') { size = 2; token_kind = CHAR64("-="); }
        else if (c0 == '*' && c1 == '=') { size = 2; token_kind = CHAR64("*="); }
        else if (c0 == '/' && c1 == '=') { size = 2; token_kind = CHAR64("/="); }
        else if (c0 == '%' && c1 == '=') { size = 2; token_kind = CHAR64("%="); }
        else if (c0 == '&' && c1 == '=') { size = 2; token_kind = CHAR64("&="); }
        else if (c0 == '^' && c1 == '=') { size = 2; token_kind = CHAR64("^="); }
        else if (c0 == '|' && c1 == '=') { size = 2; token_kind = CHAR64("|="); }
        else if (c0 == '=' && c1 == '=') { size = 2; token_kind = CHAR64("=="); }
        else if (c0 == '!' && c1 == '=') { size = 2; token_kind = CHAR64("!="); }
        else if (c0 == '<' && c1 == '=') { size = 2; token_kind = CHAR64("<="); }
        else if (c0 == '>' && c1 == '=') { size = 2; token_kind = CHAR64(">="); }
        else if (c0 == '<' && c1 == '<') { size = 2; token_kind = CHAR64("<<"); }
        else if (c0 == '>' && c1 == '>') { size = 2; token_kind = CHAR64(">>"); }
        else if (c0 == '-' && c1 == '>') { size = 2; token_kind = CHAR64("->"); }
        else if (c0 == '.' && c1 == '&') { size = 2; token_kind = CHAR64(".&"); }
        else if (c0 == '.' && c1 == '*') { size = 2; token_kind = CHAR64(".*"); }
        else if (c0 == '+') { size = 1; token_kind = c0; }
        else if (c0 == '-') { size = 1; token_kind = c0; }
        else if (c0 == '*') { size = 1; token_kind = c0; }
        else if (c0 == '/') { size = 1; token_kind = c0; }
        else if (c0 == '%') { size = 1; token_kind = c0; }
        else if (c0 == '&') { size = 1; token_kind = c0; }
        else if (c0 == '^') { size = 1; token_kind = c0; }
        else if (c0 == '|') { size = 1; token_kind = c0; }
        else if (c0 == '=') { size = 1; token_kind = c0; }
        else if (c0 == '<') { size = 1; token_kind = c0; }
        else if (c0 == '>') { size = 1; token_kind = c0; }
        else if (c0 == ';') { size = 1; token_kind = c0; }
        else if (c0 == ',') { size = 1; token_kind = c0; }
        else if (c0 == '.') { size = 1; token_kind = c0; }
        else if (c0 == ':') { size = 1; token_kind = c0; }
        else if (c0 == '(') { size = 1; token_kind = c0; }
        else if (c0 == ')') { size = 1; token_kind = c0; }
        else if (c0 == '{') { size = 1; token_kind = c0; }
        else if (c0 == '}') { size = 1; token_kind = c0; }
        else if (c0 == '[') { size = 1; token_kind = c0; }
        else if (c0 == ']') { size = 1; token_kind = c0; }
        
        error_assert(size != 0);
        
        cp += size;
      }
      
      debug_assert(token_kind != 0);
      
      Token *token = arena_push(keep_arena, sizeof(*token));
      
      token->at = token_beg;
      token->size = cp - token_beg;
      token->kind = token_kind;
      token->file = input_text;
      
      num_input_tokens += 1;
    }
  }
  
  // print all tokens:
  if (0)
  {
    console_error_print_cstring(CSTRING("  TOKENS:\n"));
    
    s64 line_length = 0;
    
    for (s64 i = 0; i < num_input_tokens; i += 1)
    {
      Token *ith = input_tokens + i;
      
      s64 size = 1 + ith->size + 3;
      
      if (line_length + size > 100)
      {
        line_length = 0;
      }
      
      console_error_print_cstring(CSTRING("'"));
      console_error_print_bytes(ith->size, ith->at);
      console_error_print_cstring(CSTRING("'  "));
      
      line_length += size;
    }
    
    console_error_print_cstring(CSTRING("\n\n"));
  }
  
  // parse the input and construct the AST
  Ast_Node *root = NULL;
  {
    Parser _parser = {0};
    Parser *parser = &_parser;
    
    parser->tokens = input_tokens;
    parser->num_tokens = num_input_tokens;
    
    error_assert(input_text[0] != '\0');
    
    arena_push_aligner(keep_arena, alignof(Token));
    
    parser->before_first = arena_push(keep_arena, sizeof(Token));
    parser->before_first->file = input_text;
    parser->before_first->at = input_text;
    parser->before_first->kind = CHAR64("invalid");
    parser->before_first->size = 0;
    
    parser->after_last = arena_push(keep_arena, sizeof(Token));
    parser->after_last->file = input_text;
    parser->after_last->at = input_text;
    parser->after_last->kind = CHAR64("invalid");
    parser->after_last->size = 0;
    
    while (parser->after_last->at[1] != '\0')
      parser->after_last->at += 1;
    
    // complain on every token:
    if (0)
    {
      console_error_print_cstring(CSTRING("  COMPLAINS:\n"));
      
      for (s64 i = -1; i <= parser->num_tokens; i += 1)
      {
        complain(COMPLAIN_NOTE, parser_safe_at(parser, i), CSTRING("this"));
      }
      
      console_error_print_cstring(CSTRING("\n"));
    }
    
    root = ast_create_node(CHAR64("root"), parser->before_first);
    
    Arena *temp_arena = get_temp_arena(NULL);
    void *items_base = arena_get_top(temp_arena);
    
    while (parser_tokens_left(parser) > 0)
    {
      if (parser_accept(parser, CHAR64("c_enum")))
      {
        Token *c_enum_token = parser_at(parser, -1);
        
        if (!parser_inspect(parser, CHAR64("{")))
          complain(0, parser_safe_at(parser, 0), CSTRING("expected the openning curly brace '{' after c_enum"));
        
        Ast_Node *global = parse_statement(parser);
        global->kind = CHAR64("c_enum");
        global->token = c_enum_token;
        
        for (s64 i = 0; i < global->num_items; i += 1)
        {
          Ast_Node *node = global->items[i];
          
          if (node->kind != CHAR64("name"))
            complain(0, node->token, CSTRING("not a name in the c_enum"));
          
          arena_push_aligner(keep_arena, alignof(Symbol));
          Symbol *symbol = arena_push(keep_arena, sizeof(Symbol));
          symbol->token = node->token;
          symbol->ast_node = node;
          
          g_next_address += 1;
          s64 address = g_next_address;
          symbol->c_name = arena_get_top(keep_arena);
          arena_print_address(keep_arena, address);
          arena_push(keep_arena, 1);
          
          node->symbol_by_name = symbol;
        }
        
        arena_push_copy(temp_arena, sizeof(global), &global);
        root->num_items += 1;
      }
      else
      {
        Ast_Node *global = parse_expression(parser, 0);
        
        if (global->kind == CHAR64("a:b")
         && global->expr_1->kind == CHAR64("(a)->b")
         && parser_inspect(parser, CHAR64("{")))
        {
          global->stmt_0 = parse_statement(parser);
        }
        else
        {
          parser_expect(parser, CHAR64(";"), CSTRING("the semicolon ';' after the global declartion"));
        }
        
        arena_push_copy(temp_arena, sizeof(global), &global);
        root->num_items += 1;
      }
    }
    
    arena_push_aligner(keep_arena, alignof(Ast_Node *));
    root->items = arena_push_copy(keep_arena, root->num_items * sizeof(Ast_Node *), items_base);
    arena_pop_to_pointer(temp_arena, items_base);
  }
  
  // print the entire AST
  if (0)
  {
    ast_debug_print_to_console_error(root);
  }
  
  // compute all scopes
    
  scope_define_recursively(root, NULL);
  
  // print the entire AST with scopes
  if (0)
  {
    ast_debug_print_to_console_error(root);
  }
  
  fe_compile_statement_recursively(root, NULL, NULL);
  
  // print the precompiled AST
  if (0)
  {
    ast_debug_print_to_console_error(root);
  }
  
  return root;
}

static void c89_compile_integer_constant(u64 value, Arena *output_arena)
{
  if (value <= 0xFFFFFFFF)
  {
    arena_print_cstring(output_arena, CSTRING("(s64)0x"));
    arena_print_u64(output_arena, value, 16, 0);
  }
  else
  {
    debug_assert(0 && "I don't need it for self-hosting");
    
    arena_print_cstring(output_arena, CSTRING("(((u64)0x"));
    arena_print_u64(output_arena, (value >> 32) & 0xFFFFFFFF, 16, 0);
    arena_print_cstring(output_arena, CSTRING(" << 32) | ((u64)0x"));
    arena_print_u64(output_arena, (value >> 0 ) & 0xFFFFFFFF, 16, 0);
    arena_print_cstring(output_arena, CSTRING("))"));
  }
}

static void c89_compile_expression_recursively(Ast_Node *expr, Arena *output_arena)
{
  debug_assert(expr != NULL);
  debug_assert(output_arena != NULL);
  
  u64 expr_kind = expr->kind;
  
  u8 *binary_cstring = NULL;
  u8 *unary_cstring = NULL;
  
  if (0) {}
  else if (expr_kind == CHAR64("a+b"    )) binary_cstring = CSTRING("+"  );
  else if (expr_kind == CHAR64("a-b"    )) binary_cstring = CSTRING("-"  );
  else if (expr_kind == CHAR64("a*b"    )) binary_cstring = CSTRING("*"  );
  else if (expr_kind == CHAR64("a/b"    )) binary_cstring = CSTRING("/"  );
  else if (expr_kind == CHAR64("a%b"    )) binary_cstring = CSTRING("%"  );
  else if (expr_kind == CHAR64("a&b"    )) binary_cstring = CSTRING("&"  );
  else if (expr_kind == CHAR64("a|b"    )) binary_cstring = CSTRING("|"  );
  else if (expr_kind == CHAR64("a^b"    )) binary_cstring = CSTRING("^"  );
  else if (expr_kind == CHAR64("a<b"    )) binary_cstring = CSTRING("<"  );
  else if (expr_kind == CHAR64("a>b"    )) binary_cstring = CSTRING(">"  );
  else if (expr_kind == CHAR64("a=b"    )) binary_cstring = CSTRING("="  );
  else if (expr_kind == CHAR64("a+=b"   )) binary_cstring = CSTRING("+=" );
  else if (expr_kind == CHAR64("a-=b"   )) binary_cstring = CSTRING("-=" );
  else if (expr_kind == CHAR64("a*=b"   )) binary_cstring = CSTRING("*=" );
  else if (expr_kind == CHAR64("a/=b"   )) binary_cstring = CSTRING("/=" );
  else if (expr_kind == CHAR64("a%=b"   )) binary_cstring = CSTRING("%=" );
  else if (expr_kind == CHAR64("a&=b"   )) binary_cstring = CSTRING("&=" );
  else if (expr_kind == CHAR64("a|=b"   )) binary_cstring = CSTRING("|=" );
  else if (expr_kind == CHAR64("a^=b"   )) binary_cstring = CSTRING("^=" );
  else if (expr_kind == CHAR64("a<=b"   )) binary_cstring = CSTRING("<=" );
  else if (expr_kind == CHAR64("a>=b"   )) binary_cstring = CSTRING(">=" );
  else if (expr_kind == CHAR64("a==b"   )) binary_cstring = CSTRING("==" );
  else if (expr_kind == CHAR64("a!=b"   )) binary_cstring = CSTRING("!=" );
  else if (expr_kind == CHAR64("a<<b"   )) binary_cstring = CSTRING("<<" );
  else if (expr_kind == CHAR64("a>>b"   )) binary_cstring = CSTRING(">>" );
  else if (expr_kind == CHAR64("a<<=b"  )) binary_cstring = CSTRING("<<=");
  else if (expr_kind == CHAR64("a>>=b"  )) binary_cstring = CSTRING(">>=");
  else if (expr_kind == CHAR64("a and b")) binary_cstring = CSTRING("&&" );
  else if (expr_kind == CHAR64("a or b" )) binary_cstring = CSTRING("||" );
  else if (expr_kind == CHAR64("+a"   )) unary_cstring = CSTRING("+");
  else if (expr_kind == CHAR64("-a"   )) unary_cstring = CSTRING("-");
  else if (expr_kind == CHAR64("^a"   )) unary_cstring = CSTRING("~");
  else if (expr_kind == CHAR64("not a")) unary_cstring = CSTRING("!");
  else if (expr_kind == CHAR64("a.*"  )) unary_cstring = CSTRING("*");
  else if (expr_kind == CHAR64("a.&"  )) unary_cstring = CSTRING("&");
  
  if (binary_cstring != NULL)
  {
    debug_assert(expr->expr_0 != NULL);
    debug_assert(expr->expr_1 != NULL);
    
    arena_print_cstring(output_arena, CSTRING("("));
    c89_compile_expression_recursively(expr->expr_0, output_arena);
    arena_print_cstring(output_arena, CSTRING(") "));
    arena_print_cstring(output_arena, binary_cstring);
    arena_print_cstring(output_arena, CSTRING(" ("));
    c89_compile_expression_recursively(expr->expr_1, output_arena);
    arena_print_cstring(output_arena, CSTRING(")"));
  }
  else if (unary_cstring != NULL)
  {
    debug_assert(expr->expr_0 != NULL);
    
    arena_print_cstring(output_arena, unary_cstring);
    arena_print_cstring(output_arena, CSTRING("("));
    c89_compile_expression_recursively(expr->expr_0, output_arena);
    arena_print_cstring(output_arena, CSTRING(")"));
  }
  else if (expr_kind == CHAR64("name"))
  {
    Symbol *symbol = expr->symbol_by_name;
    debug_assert(symbol != NULL);

    if (symbol->storage != STORAGE_C_ENUM)
    {
      arena_print_cstring(output_arena, symbol->c_name);
    }
    else
    {
      c89_compile_integer_constant(symbol->c_enum_value, output_arena);
    }
  }
  else if (expr_kind == CHAR64("null"))
  {
    arena_print_cstring(output_arena, CSTRING("NULL"));
  }
  else if (expr_kind == CHAR64("c_string"))
  {
    Arena *temp_arena = get_temp_arena(NULL);
    u8 *bytes = arena_get_top(temp_arena);
    s64 size = bytes_from_extended_text(expr->token->size - 2, expr->token->at + 1, temp_arena);
    
    arena_print_cstring(output_arena, CSTRING("(u8 *)\""));
    
    for (s64 i = 0; i < size; i += 1)
    {
      arena_print_cstring(output_arena, CSTRING("\\x"));
      arena_print_u64(output_arena, bytes[i], 16, 2);
    }
    
    arena_print_cstring(output_arena, CSTRING("\""));
    
    arena_pop_to_pointer(temp_arena, bytes);
  }
  else if (expr_kind == CHAR64("'"))
  {
    Arena *temp_arena = get_temp_arena(NULL);
    u8 *bytes = arena_get_top(temp_arena);
    s64 size = bytes_from_extended_text(expr->token->size - 2, expr->token->at + 1, temp_arena);
    
    u64 value = 0;
    
    for (s64 i = 0; i < size; i += 1)
    {
      value <<= 8;
      value |= bytes[i];
    }
    
    arena_pop_to_pointer(temp_arena, bytes);
    
    c89_compile_integer_constant(value, output_arena);
  }
  else if (expr_kind == CHAR64("c_dbgpos"))
  {
    Arena *temp_arena = get_temp_arena(NULL);
    u8 *bytes = arena_get_top(temp_arena);
    
    //
    
    s64 row = 1;
    s64 col = 1;
    
    for (u8 *cp = expr->token->file; cp != expr->token->at; cp += 1)
    {
      if (*cp == '\n')
      {
        row += 1;
        col = 0;
      }
      
      col += 1;
    }
    
    u8 *line_at = expr->token->at - (col - 1);
    s64 line_size = 0;
    
    while (line_at[line_size] != '\0' && line_at[line_size] != '\n')
      line_size += 1;
    
    arena_print_s64(temp_arena, row, 10, 0);
    arena_print_cstring(temp_arena, CSTRING(": c_dbgpos: "));
    
    arena_print_bytes(temp_arena, line_size, line_at);
    
    s64 size = (u8 *)arena_get_top(temp_arena) - bytes;
    
    //
    
    arena_print_cstring(output_arena, CSTRING("(u8 *)\""));
    
    for (s64 i = 0; i < size; i += 1)
    {
      arena_print_cstring(output_arena, CSTRING("\\x"));
      arena_print_u64(output_arena, bytes[i], 16, 2);
    }
    
    arena_print_cstring(output_arena, CSTRING("\""));
    
    //
    
    arena_pop_to_pointer(temp_arena, bytes);
  }
  else if (expr_kind == CHAR64("integer"))
  {
    debug_assert(expr->value.is_constexpr);
    c89_compile_integer_constant(expr->value.as_u64, output_arena);
  }
  else if (expr_kind == CHAR64("size_of"))
  {
    debug_assert(expr->value.is_constexpr);
    c89_compile_integer_constant(expr->value.as_u64, output_arena);
  }
  else if (expr_kind == CHAR64("align_of"))
  {
    debug_assert(expr->value.is_constexpr);
    c89_compile_integer_constant(expr->value.as_u64, output_arena);
  }
  else if (expr_kind == CHAR64("a(b)"))
  {
    arena_print_cstring(output_arena, CSTRING("("));
    c89_compile_expression_recursively(expr->expr_0, output_arena);
    arena_print_cstring(output_arena, CSTRING(")"));
    
    Type *function_type = expr->expr_0->value.type;
    
    if (function_type->kind == CHAR64("*a"))
      function_type = function_type->sub_type;

    arena_print_cstring(output_arena, CSTRING("("));
    
    for (s64 i = 0; i < expr->num_items; i += 1)
    {
      Ast_Node *arg = expr->items[i];
      Expr_Value arg_value = rvalue_from(arg->value);
      
      Type *param_type = function_type->params[i];
      
      if (type_is_integer(param_type) && type_is_integer(arg_value.type))
      {
        s64 dst_size = type_size_of(param_type);
        s64 src_size = type_size_of(arg_value.type);
        
        if (dst_size < src_size)
        {
          arena_print_cstring(output_arena, CSTRING("("));
          arena_print_char64(output_arena, param_type->kind);
          arena_print_cstring(output_arena, CSTRING(")"));
        }
      }
      
      arena_print_cstring(output_arena, CSTRING("("));
      c89_compile_expression_recursively(arg, output_arena);
      arena_print_cstring(output_arena, CSTRING(")"));
      
      if (i + 1 < expr->num_items)
        arena_print_cstring(output_arena, CSTRING(", "));
    }
    
    arena_print_cstring(output_arena, CSTRING(")"));
  }
  else if (expr_kind == CHAR64("a[b]"))
  {
    arena_print_cstring(output_arena, CSTRING("("));
    c89_compile_expression_recursively(expr->expr_0, output_arena);
    arena_print_cstring(output_arena, CSTRING(")"));
    arena_print_cstring(output_arena, CSTRING("["));
    c89_compile_expression_recursively(expr->expr_1, output_arena);
    arena_print_cstring(output_arena, CSTRING("]"));
  }
  else if (expr_kind == CHAR64("cast"))
  {
    Type *dst_type = expr->value.type;
    Type *src_type = expr->expr_0->value.type;
    
    (void) src_type;
    
    if ( (src_type->kind == CHAR64("(a)->b") || (src_type->kind == CHAR64("*a") && src_type->sub_type->kind == CHAR64("(a)->b")))
      && (dst_type->kind == CHAR64("*a") && dst_type->sub_type->kind == CHAR64("void")) )
    {
      complain(0, expr->token, CSTRING("I don't know how to do this in C89 without warnings"));
    }
    else
    {
      arena_print_cstring(output_arena, CSTRING("("));
      
      Arena *temp_arena = get_temp_arena(NULL);
      void *temp_top = arena_get_top(temp_arena);
      
      u8 *ctype_cstring = declaration_from_type_and_center(dst_type, CSTRING(""), temp_arena);
      arena_print_cstring(output_arena, ctype_cstring);
      
      arena_pop_to_pointer(temp_arena, temp_top);
      
      arena_print_cstring(output_arena, CSTRING(")"));
      
      arena_print_cstring(output_arena, CSTRING("("));
      c89_compile_expression_recursively(expr->expr_0, output_arena);
      arena_print_cstring(output_arena, CSTRING(")"));
    }
  }
  else if (expr_kind == CHAR64("a.b"))
  {
    arena_print_cstring(output_arena, CSTRING("("));
    c89_compile_expression_recursively(expr->expr_0, output_arena);
    arena_print_cstring(output_arena, CSTRING(")"));
    
    if (expr->expr_0->value.type->kind == CHAR64("*a"))
    {
      arena_print_cstring(output_arena, CSTRING("->"));
    }
    else
    {
      arena_print_cstring(output_arena, CSTRING("."));
    }
    
    u8 *c_member_name = expr->value.type->c_name_opt;
    debug_assert(c_member_name != NULL);
    arena_print_cstring(output_arena, c_member_name);
  }
  else
  {
    complain(0, expr->token, CSTRING("iduno how to compile this"));
  }
}

static void c89_compile_statement_recursively(Ast_Node *stmt, s64 spaces, Arena *output_arena);

static void c89_compile_block(Ast_Node *block_stmt, s64 spaces, Arena *output_arena)
{
  if (block_stmt->kind == CHAR64("stmtlist"))
  {
    c89_compile_statement_recursively(block_stmt, spaces, output_arena);
  }
  else
  {
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("{\n"));
    c89_compile_statement_recursively(block_stmt, spaces + 2, output_arena);
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("}\n"));
  }
}

static void c89_compile_local_symbol(Symbol *symbol, s64 sub_spaces, Arena *output_arena)
{
  debug_assert(symbol != NULL);
  debug_assert(symbol->type != NULL);
  
  debug_assert(symbol->storage != STORAGE_C_TYPEDEF);

  // compile the declaration:
  
  Arena *temp_arena = get_temp_arena(NULL);
  void *temp_top = arena_get_top(temp_arena);
  
  u8 *center = print_declaration_center_from_symbol(symbol, temp_arena);
  
  arena_print_row(output_arena, sub_spaces, ' ');
  
  if (symbol->storage == STORAGE_EXTERN)
  {
    arena_print_cstring(output_arena, CSTRING("extern "));
  }
  else if (symbol->storage == STORAGE_STATIC)
  {
    arena_print_cstring(output_arena, CSTRING("static "));
  }
  
  u8 *declaration_cstring = declaration_from_type_and_center(symbol->type, center, temp_arena);
  arena_print_cstring(output_arena, declaration_cstring);
  
  arena_pop_to_pointer(temp_arena, temp_top);
  
  if (symbol->storage == STORAGE_LOCAL)
  {
    if (symbol->type->kind == CHAR64("*a"))
    {
      arena_print_cstring(output_arena, CSTRING(" = NULL"));
    }
    else if (symbol->type->kind == CHAR64("struct"))
    {
      arena_print_cstring(output_arena, CSTRING(" = {0}"));
    }
    else
    {
      arena_print_cstring(output_arena, CSTRING(" = 0"));
    }
  }
  
  arena_print_cstring(output_arena, CSTRING(";\n"));
}

static void c89_compile_statement_recursively(Ast_Node *stmt, s64 spaces, Arena *output_arena)
{
  u64 stmt_kind = stmt->kind;
  
  if (stmt_kind == CHAR64("root"))
  {
    Ast_Node *root = stmt;
    Ast_Node *scope_holder = stmt;
    
    //
    
    s64 num_typedefs = 0;
    
    for (s64 i = 0; i < scope_holder->scope.num_symbols; i += 1)
    {
      Symbol *symbol = scope_holder->scope.symbols[i];
      debug_assert(symbol != NULL);
      debug_assert(symbol->type != NULL);
      
      if (symbol->storage == STORAGE_C_TYPEDEF)
      {
        debug_assert(symbol->type->kind == CHAR64("struct"));
        
        arena_print_row(output_arena, spaces, ' ');
        arena_print_cstring(output_arena, CSTRING("typedef struct "));
        arena_print_cstring(output_arena, symbol->type->struct_c_name);
        arena_print_cstring(output_arena, CSTRING(" "));
        arena_print_cstring(output_arena, symbol->type->struct_c_name);
        arena_print_cstring(output_arena, CSTRING(";\n"));
        
        num_typedefs += 1;
      }
    }
    
    if (num_typedefs > 0)
      arena_print_cstring(output_arena, CSTRING("\n"));
    
    //
    
    s64 num_structs = 0;
    
    for (s64 i = 0; i < scope_holder->scope.num_symbols; i += 1)
    {
      Symbol *symbol = scope_holder->scope.symbols[i];
      debug_assert(symbol != NULL);
      debug_assert(symbol->type != NULL);
      
      if (symbol->storage == STORAGE_C_TYPEDEF && symbol->type->kind == CHAR64("struct"))
      {
        arena_print_row(output_arena, spaces, ' ');
        arena_print_cstring(output_arena, CSTRING("struct "));
        arena_print_cstring(output_arena, symbol->type->struct_c_name);
        arena_print_cstring(output_arena, CSTRING("\n"));
        
        arena_print_row(output_arena, spaces, ' ');
        arena_print_cstring(output_arena, CSTRING("{\n"));
        
        s64 sub_spaces = spaces + 2;
        
        for (s64 k = 0; k < symbol->type->num_members; k += 1)
        {
          Type *member_type = symbol->type->members[k];
          
          arena_print_row(output_arena, sub_spaces, ' ');
          
          Arena *temp_arena = get_temp_arena(NULL);
          void *temp_top = arena_get_top(temp_arena);
          
          debug_assert(member_type->c_name_opt != NULL);
          u8 *declaration_cstring = declaration_from_type_and_center(member_type, member_type->c_name_opt, temp_arena);
          
          arena_print_cstring(output_arena, declaration_cstring);
          
          arena_pop_to_pointer(temp_arena, temp_top);
          
          arena_print_cstring(output_arena, CSTRING(";\n"));
        }
        
        arena_print_row(output_arena, spaces, ' ');
        arena_print_cstring(output_arena, CSTRING("};\n"));
        
        num_structs += 1;
      }
    }
    
    if (num_structs > 0)
      arena_print_cstring(output_arena, CSTRING("\n"));
    
    // declare:
    
    for (s64 i = 0; i < root->num_items; i += 1)
    {
      Ast_Node *ast = root->items[i];
      
      if (ast->kind == CHAR64("a:b"))
      {
        Symbol *symbol = ast->expr_0->symbol_by_name;
        debug_assert(symbol != NULL);
        debug_assert(symbol->type != NULL);
        
        if (symbol->storage == STORAGE_C_TYPEDEF)
          continue;
        
        // compile the declaration:
        
        Arena *temp_arena = get_temp_arena(NULL);
        void *temp_top = arena_get_top(temp_arena);
        
        u8 *center = print_declaration_center_from_symbol(symbol, temp_arena);
        
        arena_print_row(output_arena, spaces, ' ');
        
        if (symbol->storage == STORAGE_EXTERN)
        {
          arena_print_cstring(output_arena, CSTRING("extern "));
        }
        else if (symbol->storage == STORAGE_STATIC)
        {
          arena_print_cstring(output_arena, CSTRING("static "));
        }
        
        u8 *declaration_cstring = declaration_from_type_and_center(symbol->type, center, temp_arena);
        arena_print_cstring(output_arena, declaration_cstring);
        
        arena_pop_to_pointer(temp_arena, temp_top);
        
        arena_print_cstring(output_arena, CSTRING(";\n"));
      }
    }
    
    arena_print_cstring(output_arena, CSTRING("\n"));
    
    // compile all the children:
    
    for (s64 i = 0; i < root->num_items; i += 1)
    {
      c89_compile_statement_recursively(root->items[i], spaces, output_arena);
    }
  }
  else if (stmt_kind == CHAR64("stmtlist"))
  {
    Ast_Node *list = stmt;
    
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("{\n"));
    
    s64 sub_spaces = spaces + 2;
    
    // declare:
    
    s64 num_decls = 0;
    
    for (s64 i = 0; i < list->num_items; i += 1)
    {
      Ast_Node *ast = list->items[i];
      
      if (ast->kind == CHAR64("a:b"))
      {
        Symbol *symbol = ast->expr_0->symbol_by_name;
        
        c89_compile_local_symbol(symbol, sub_spaces, output_arena);
        
        num_decls += 1;
      }
    }
    
    if (num_decls > 0)
      arena_print_cstring(output_arena, CSTRING("\n"));
    
    s64 num_voided = 0;
  
    for (s64 i = 0; i < list->scope.num_symbols; i += 1)
    {
      Symbol *symbol = list->scope.symbols[i];
      
      if (symbol->num_uses == 0)
      {
        arena_print_row(output_arena, sub_spaces, ' ');
        arena_print_cstring(output_arena, CSTRING("(void) "));
        arena_print_cstring(output_arena, symbol->c_name);
        arena_print_cstring(output_arena, CSTRING(";\n"));
        num_voided += 1;
      }
    }
    
    if (num_voided > 0)
      arena_print_cstring(output_arena, CSTRING("\n"));
    
    // compile all the children:
    
    for (s64 i = 0; i < list->num_items; i += 1)
    {
      c89_compile_statement_recursively(list->items[i], sub_spaces, output_arena);
    }
    
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("}\n"));
  }
  else if (stmt_kind == CHAR64("c_for"))
  {
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("{\n"));
    
    s64 sub_spaces = spaces + 2;
    
    if (stmt->expr_0)
    {
      debug_assert(stmt->expr_0->kind == CHAR64("a:b"));
      
      Symbol *symbol = stmt->expr_0->expr_0->symbol_by_name;
      debug_assert(symbol != NULL);
      
      c89_compile_local_symbol(symbol, sub_spaces, output_arena);
      
      if (symbol->num_uses == 0)
      {
        arena_print_row(output_arena, sub_spaces, ' ');
        arena_print_cstring(output_arena, CSTRING("(void) "));
        arena_print_cstring(output_arena, symbol->c_name);
        arena_print_cstring(output_arena, CSTRING(";\n"));
      }
    }
    
    arena_print_row(output_arena, sub_spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("for (;"));
    
    if (stmt->expr_1)
    {
      arena_print_cstring(output_arena, CSTRING(" "));
      c89_compile_expression_recursively(stmt->expr_1, output_arena);
    }
    
    arena_print_cstring(output_arena, CSTRING(";"));
    
    if (stmt->expr_2)
    {
      arena_print_cstring(output_arena, CSTRING(" "));
      c89_compile_expression_recursively(stmt->expr_2, output_arena);
    }
    
    arena_print_cstring(output_arena, CSTRING(")\n"));
    
    c89_compile_block(stmt->stmt_0, sub_spaces, output_arena);
    
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("}\n"));
  }
  else if (stmt_kind == CHAR64("c_enum"))
  {
    // do nothing.
  }
  else if (stmt_kind == CHAR64("continue"))
  {
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("continue;\n"));
  }
  else if (stmt_kind == CHAR64("break"))
  {
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("break;\n"));
  }
  else if (stmt_kind == CHAR64("a:b") && stmt->expr_1->kind == CHAR64("(a)->b") && stmt->stmt_0 != NULL)
  {
    Ast_Node *func = stmt;
    Symbol *symbol = func->expr_0->symbol_by_name;
        
    Arena *temp_arena = get_temp_arena(NULL);
    void *temp_top = arena_get_top(temp_arena);
    
    u8 *center = print_declaration_center_from_symbol(symbol, temp_arena);
    
    u8 *declaration_cstring = declaration_from_type_and_center(symbol->type, center, temp_arena);
    arena_print_cstring(output_arena, CSTRING("\n"));
    
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, declaration_cstring);
    
    arena_pop_to_pointer(temp_arena, temp_top);
    
    arena_print_cstring(output_arena, CSTRING("\n"));
    
    c89_compile_statement_recursively(func->stmt_0, spaces, output_arena);
  }
  else if (stmt_kind == CHAR64("a:b"))
  {
    // do nothing?
  }
  else if (stmt_kind == CHAR64("while"))
  {
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("while ("));
    c89_compile_expression_recursively(stmt->expr_0, output_arena);
    arena_print_cstring(output_arena, CSTRING(")\n"));
    
    c89_compile_block(stmt->stmt_0, spaces, output_arena);
  }
  else if (stmt_kind == CHAR64("do-while"))
  {
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("do\n"));
    
    c89_compile_block(stmt->stmt_0, spaces, output_arena);
    
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("while ("));
    c89_compile_expression_recursively(stmt->expr_0, output_arena);
    arena_print_cstring(output_arena, CSTRING(");\n"));
  }
  else if (stmt_kind == CHAR64("if-else"))
  {
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("if ("));
    c89_compile_expression_recursively(stmt->expr_0, output_arena);
    arena_print_cstring(output_arena, CSTRING(")\n"));
    
    c89_compile_block(stmt->stmt_0, spaces, output_arena);

    Ast_Node *next_else = stmt->stmt_1;
    
    while (next_else != NULL && next_else->kind == CHAR64("if-else"))
    {
      arena_print_row(output_arena, spaces, ' ');
      arena_print_cstring(output_arena, CSTRING("else if ("));
      c89_compile_expression_recursively(next_else->expr_0, output_arena);
      arena_print_cstring(output_arena, CSTRING(")\n"));
      
      c89_compile_block(next_else->stmt_0, spaces, output_arena);
      
      next_else = next_else->stmt_1;
    }
    
    if (next_else != NULL)
    {
      arena_print_row(output_arena, spaces, ' ');
      arena_print_cstring(output_arena, CSTRING("else\n"));
      c89_compile_block(next_else, spaces, output_arena);
    }
  }
  else if (stmt_kind == CHAR64("return"))
  {
    arena_print_row(output_arena, spaces, ' ');
    arena_print_cstring(output_arena, CSTRING("return"));
    
    if (stmt->expr_0)
    {
      arena_print_cstring(output_arena, CSTRING(" "));
      c89_compile_expression_recursively(stmt->expr_0, output_arena);
    }
    
    arena_print_cstring(output_arena, CSTRING(";\n"));
  }
  else
  {
    arena_print_row(output_arena, spaces, ' ');
    c89_compile_expression_recursively(stmt, output_arena);
    arena_print_cstring(output_arena, CSTRING(";\n"));
  }
}

static void c89_backend(Ast_Node *root, Arena *output_arena)
{
  Symbol *main_symbol = array_find_symbol_by_name(root->scope.num_symbols, root->scope.symbols, 4, CSTRING("main"));
  
  if (main_symbol == NULL)
    complain(0, NULL, CSTRING("'main' function must be defined"));
  
  main_symbol->num_uses += 1;
  
  arena_print_cstring(output_arena, CSTRING("\n"));
  arena_print_cstring(output_arena, CSTRING("#include <stddef.h>\n"));
  arena_print_cstring(output_arena, CSTRING("#include <stdint.h>\n"));
  arena_print_cstring(output_arena, CSTRING("\n"));
  arena_print_cstring(output_arena, CSTRING("typedef uint8_t  u8;\n"));
  arena_print_cstring(output_arena, CSTRING("typedef uint16_t u16;\n"));
  arena_print_cstring(output_arena, CSTRING("typedef uint32_t u32;\n"));
  arena_print_cstring(output_arena, CSTRING("typedef uint64_t u64;\n"));
  arena_print_cstring(output_arena, CSTRING("typedef int8_t   s8;\n"));
  arena_print_cstring(output_arena, CSTRING("typedef int16_t  s16;\n"));
  arena_print_cstring(output_arena, CSTRING("typedef int32_t  s32;\n"));
  arena_print_cstring(output_arena, CSTRING("typedef int64_t  s64;\n"));
  arena_print_cstring(output_arena, CSTRING("\n"));
  
  c89_compile_statement_recursively(root, 0, output_arena);
  
  // the runtime:
  
  arena_print_cstring(output_arena, CSTRING("\n"));
  arena_print_cstring(output_arena, CSTRING("void _start(void)\n"));
  arena_print_cstring(output_arena, CSTRING("{\n"));
  arena_print_cstring(output_arena, CSTRING("  extern void ExitProcess(u32 status);\n"));
  arena_print_cstring(output_arena, CSTRING("  \n"));
  
  s64 num_voided = 0;
  
  for (s64 i = 0; i < root->scope.num_symbols; i += 1)
  {
    Symbol *symbol = root->scope.symbols[i];
    
    if (symbol->num_uses == 0 && symbol->storage == STORAGE_STATIC)
    {
      arena_print_cstring(output_arena, CSTRING("  (void) "));
      arena_print_cstring(output_arena, symbol->c_name);
      arena_print_cstring(output_arena, CSTRING(";\n"));
      num_voided += 1;
    }
  }
  
  if (num_voided > 0)
    arena_print_cstring(output_arena, CSTRING("  \n"));
  
  debug_assert(main_symbol->type != NULL);
  
  if (main_symbol->type->kind != CHAR64("(a)->b")
   || main_symbol->type->sub_type->kind != CHAR64("void")
   || main_symbol->type->num_params != 0)
    complain(0, main_symbol->token, CSTRING("'main' must be a function of type '() -> void'"));
  
  arena_print_cstring(output_arena, CSTRING("  "));
  arena_print_cstring(output_arena, main_symbol->c_name);
  arena_print_cstring(output_arena, CSTRING("();\n"));
  
  arena_print_cstring(output_arena, CSTRING("  ExitProcess(0);\n"));
  arena_print_cstring(output_arena, CSTRING("}\n"));
  
  arena_print_cstring(output_arena, CSTRING("\n"));
  arena_print_cstring(output_arena, CSTRING("\n"));
  arena_print_cstring(output_arena, CSTRING("\n"));
}

// the entry-point

void _start(void)
{
  console_init();
  
  debug_assert(sizeof(u64) == 8);
  debug_assert(sizeof(s64) == 8);
  
  keep_arena   = arena_create((s64)0x400 * 0x400 * 0x400); // 1 GB
  temp_arena_0 = arena_create((s64)0x400 * 0x400 * 0x400); // 1 GB
  temp_arena_1 = arena_create((s64)0x400 * 0x400 * 0x400); // 1 GB
  
  // parse command-line arguments:
  u8 *input_path = CSTRING("a.c");
  u8 *output_path = CSTRING("a.c");
  {
    s64 num_input_files = 0;
    u8 **arguments = command_get_arguments(keep_arena, temp_arena_0);
    
    for (s64 i = 0; arguments[i] != NULL; i += 1)
    {
      u8 *argument = arguments[i];
      s64 length = cstring_length(argument);
      
      if (length == 2 && memory_equal(argument, CSTRING("-o"), 2))
      {
        error_assert(arguments[i + 1] != NULL);
        
        i += 1;
        output_path = arguments[i];
      }
      else
      {
        input_path = argument;
        num_input_files += 1;
        error_assert(num_input_files <= 1);
      }
    }
  }
  
  // print the task
  if (0)
  {
    console_error_print_cstring(CSTRING("  TASK:\ninput: "));
    console_error_print_cstring(input_path);
    console_error_print_cstring(CSTRING("\noutput: "));
    console_error_print_cstring(output_path);
    console_error_print_cstring(CSTRING("\n\n"));
  }
  
  Ast_Node *root = language_frontend(input_path);
  
  Arena *output_arena = arena_create((s64)0x400 * 0x400 * 0x400); // 1 GB
  
  c89_backend(root, output_arena);
  
  // write the result:
  {
    u32 ok = file_write_all_bytes(output_path, output_arena->pushed, output_arena->at);
    resource_assert(ok);
  }
  
  // the end:
  {
    console_error_print_cstring(CSTRING("SUCCESS!\n"));
    process_exit(0);
  }
}


