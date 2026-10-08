
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

typedef struct A_00001 A_00001;
typedef struct A_00007 A_00007;
typedef struct A_0000D A_0000D;
typedef struct A_00019 A_00019;
typedef struct A_00025 A_00025;
typedef struct A_0002C A_0002C;
typedef struct A_00031 A_00031;
typedef struct A_00038 A_00038;

struct A_00001
{
  u8 (*A_00002);
  s64 A_00003;
  s64 A_00004;
  s64 A_00005;
};
struct A_00007
{
  u8 (*A_00008);
  s64 A_00009;
  s64 A_0000A;
  u8 (*A_0000B);
};
struct A_0000D
{
  s64 A_0000E;
  A_00007 (*A_0000F);
  A_00007 (*A_00010);
  u8 (*A_00011);
  u8 (*A_00012);
  A_0000D (*A_00013);
  s64 A_00014;
  A_0000D (*(*A_00015));
  s64 A_00016;
  A_0000D (*(*A_00017));
};
struct A_00019
{
  A_00007 (*A_0001A);
  A_0000D (*A_0001B);
  void (*A_0001C);
  u8 (*A_0001D);
  A_00007 (*A_0001E);
  A_00007 (*A_0001F);
  s64 A_00020;
  u64 A_00021;
  s64 A_00022;
  s64 A_00023;
};
struct A_00025
{
  A_00007 (*A_00026);
  A_00007 (*A_00027);
  A_00007 (*A_00028);
  s64 A_00029;
  s64 A_0002A;
};
struct A_0002C
{
  A_00019 (*(*A_0002D));
  s64 A_0002E;
  A_0002C (*A_0002F);
};
struct A_00031
{
  A_00007 (*A_00032);
  A_0000D (*A_00033);
  u64 A_00034;
  u64 A_00035;
  u64 A_00036;
};
struct A_00038
{
  s64 A_00039;
  A_00007 (*A_0003A);
  A_00038 (*A_0003B);
  A_00038 (*A_0003C);
  A_00038 (*A_0003D);
  A_00038 (*A_0003E);
  A_00038 (*A_0003F);
  s64 A_00040;
  A_00038 (*(*A_00041));
  A_00019 (*A_00042);
  A_00031 A_001C7;
  A_0002C A_00044;
  u8 (*A_00045);
};

static A_00001 (*A_000F8/*keep_arena*/);
static A_00001 (*A_000F9/*temp_arena*/);
static s64 A_000FA/*g_next_address*/;
static u64 A_000FB/*option_print_actual_names*/;
static A_0000D A_000FC/*g_type_s64*/;
static A_0000D A_000FD/*g_type_u64*/;
static A_0000D A_000FE/*g_type_u32*/;
static A_0000D A_000FF/*g_type_u8*/;
static A_0000D A_00100/*g_type_void*/;
static A_0000D A_00101/*g_type_void_ptr*/;
static A_0000D A_00102/*g_type_u8_ptr*/;
static void A_00103/*main*/(void);
static s64 A_0010F/*type_alignment_of*/(A_0000D (*A_0010E/*type*/));
static s64 A_00116/*type_size_of*/(A_0000D (*A_00115/*type*/));
static u64 A_0011F/*type_explicit_cast_is_possible*/(A_0000D (*A_0011D/*dst*/), A_0000D (*A_0011E/*src*/));
static s64 A_00123/*bytes_from_extended_text*/(s64 A_00120/*length*/, u8 (*A_00121/*text*/), A_00001 (*A_00122/*result_arena*/));
static u8 (*A_0012C/*declaration_from_type_and_center*/(A_0000D (*A_00129/*type*/), u8 (*A_0012A/*center*/), A_00001 (*A_0012B/*cstring_arena*/)));
static u8 (*A_0013A/*print_declaration_center_from_symbol*/(A_00019 (*A_00138/*symbol*/), A_00001 (*A_00139/*result_arena*/)));
static void A_0013E/*c89_compile_integer_constant*/(u64 A_0013C/*value*/, A_00001 (*A_0013D/*output_arena*/));
static void A_00141/*c89_backend*/(A_00038 (*A_0013F/*root*/), A_00001 (*A_00140/*output_arena*/));
static void A_00148/*c89_compile_expression_recursively*/(A_00038 (*A_00146/*expr*/), A_00001 (*A_00147/*output_arena*/));
static void A_0016D/*c89_compile_block*/(A_00038 (*A_0016A/*block_stmt*/), s64 A_0016B/*spaces*/, A_00001 (*A_0016C/*output_arena*/));
static void A_00171/*c89_compile_local_symbol*/(A_00019 (*A_0016E/*symbol*/), s64 A_0016F/*sub_spaces*/, A_00001 (*A_00170/*output_arena*/));
static void A_00178/*c89_compile_statement_recursively*/(A_00038 (*A_00175/*stmt*/), s64 A_00176/*spaces*/, A_00001 (*A_00177/*output_arena*/));
static A_00038 (*A_0019E/*language_frontend*/(u8 (*A_0019D/*input_path*/)));
static u64 A_001BE/*type_equal*/(A_0000D (*A_001BC/*a*/), A_0000D (*A_001BD/*b*/));
static u64 A_001C2/*type_kind_is_integer*/(s64 A_001C1/*type_kind*/);
static u64 A_001C5/*type_implicit_cast_is_possible*/(A_0000D (*A_001C3/*dst*/), A_0000D (*A_001C4/*src*/));
static A_00031 A_001C8/*rvalue_from*/(A_00031 A_001C7/*value*/);
static u64 A_001CA/*type_kind_can_be_boolified*/(s64 A_001C9/*type_kind*/);
static A_00031 A_001CD/*fe_compile_expression_recursively*/(A_00038 (*A_001CB/*expr*/), A_0002C (*A_001CC/*current_scope*/));
static A_0000D (*A_00201/*type_from_ast*/(A_00038 (*A_001FF/*node*/), A_0002C (*A_00200/*current_scope*/)));
static void A_00214/*fe_compile_statement_recursively*/(A_00038 (*A_00211/*stmt*/), A_0002C (*A_00212/*current_scope*/), A_00019 (*A_00213/*current_function_symbol*/));
static void A_00228/*scope_define_recursively*/(A_00038 (*A_00226/*node*/), A_0002C (*A_00227/*parent_scope*/));
static A_00019 (*A_00233/*array_find_symbol_by_name*/(s64 A_0022F/*num_symptrs*/, A_00019 (*(*A_00230/*symptrs*/)), s64 A_00231/*name_length*/, u8 (*A_00232/*name*/)));
static A_00019 (*A_00239/*scope_find_symbol_by_name*/(A_0002C (*A_00236/*current_scope*/), s64 A_00237/*name_length*/, u8 (*A_00238/*name*/)));
static void A_0023F/*scope_append_declarations_from_list*/(A_0002C (*A_0023C/*scope*/), s64 A_0023D/*num_items*/, A_00038 (*(*A_0023E/*items*/)));
static A_00038 (*A_0024A/*parse_expression*/(A_00025 (*A_00248/*parser*/), u64 A_00249/*minimal_precedence*/));
static void A_00267/*ast_debug_print_to_console_error*/(A_00038 (*A_00266/*root*/));
static void A_0026E/*ast_debug_print_recursively*/(A_00038 (*A_00269/*node*/), u64 A_0026A/*spaces*/, u8 (*A_0026B/*title*/), s64 A_0026C/*index_opt*/, A_00001 (*A_0026D/*result_arena*/));
static void A_00276/*arena_print_address*/(A_00001 (*A_00274/*arena*/), s64 A_00275/*address*/);
static A_00038 (*A_00278/*parse_statement*/(A_00025 (*A_00277/*parser*/)));
static void A_0027D/*parser_proceed*/(A_00025 (*A_0027C/*parser*/));
static A_00007 (*A_00280/*parser_inspect*/(A_00025 (*A_0027E/*parser*/), s64 A_0027F/*token_kind*/));
static A_00007 (*A_00284/*parser_accept*/(A_00025 (*A_00282/*parser*/), s64 A_00283/*token_kind*/));
static A_00007 (*A_00289/*parser_expect*/(A_00025 (*A_00286/*parser*/), s64 A_00287/*token_kind*/, u8 (*A_00288/*what*/)));
static A_00038 (*A_0028E/*ast_create_node*/(s64 A_0028C/*node_kind_opt*/, A_00007 (*A_0028D/*token_opt*/)));
static void A_00293/*complain*/(s64 A_00290/*complain_kind*/, A_00007 (*A_00291/*token_opt*/), u8 (*A_00292/*message*/));
static s64 A_002A1/*parser_tokens_left*/(A_00025 (*A_002A0/*parser*/));
static A_00007 (*A_002A4/*parser_at*/(A_00025 (*A_002A2/*parser*/), s64 A_002A3/*relative_index*/));
static A_00007 (*A_002A8/*parser_safe_at*/(A_00025 (*A_002A6/*parser*/), s64 A_002A7/*relative_index*/));
static u8 (*A_002AC/*c_string_from_node_kind*/(s64 A_002AB/*node_kind*/));
static s64 A_002AF/*s64_align*/(s64 A_002AD/*number*/, s64 A_002AE/*alignment*/);
static s64 A_002B3/*s64_max*/(s64 A_002B1/*a*/, s64 A_002B2/*b*/);
static s64 A_002B6/*s64_min*/(s64 A_002B4/*a*/, s64 A_002B5/*b*/);
static u64 A_002B9/*u64_max*/(u64 A_002B7/*a*/, u64 A_002B8/*b*/);
static u64 A_002BC/*u64_min*/(u64 A_002BA/*a*/, u64 A_002BB/*b*/);
static void A_002C0/*memory_set_every_byte_to_value*/(void (*A_002BD/*a*/), u32 A_002BE/*value*/, s64 A_002BF/*size*/);
static void A_002C4/*memory_zero*/(void (*A_002C2/*a*/), s64 A_002C3/*size*/);
static void A_002C8/*memory_move*/(void (*A_002C5/*dst*/), void (*A_002C6/*src*/), s64 A_002C7/*size*/);
static u32 A_002D1/*memory_equal*/(void (*A_002CE/*a*/), void (*A_002CF/*b*/), s64 A_002D0/*size*/);
static void A_002D6/*memory_copy*/(void (*A_002D3/*dst*/), void (*A_002D4/*src*/), s64 A_002D5/*size*/);
static s64 A_002D9/*cstring_length*/(u8 (*A_002D8/*s*/));
static u32 A_002DC/*ascii_digit_from_int*/(s64 A_002DB/*number*/);
static s64 A_002DE/*ascii_digit_to_int*/(u32 A_002DD/*c*/);
static u64 A_002E0/*ascii_is_space*/(u64 A_002DF/*c*/);
static u64 A_002E2/*ascii_is_letter*/(u64 A_002E1/*c*/);
static u64 A_002E4/*ascii_is_letter_or_digit*/(u64 A_002E3/*c*/);
static u64 A_002E6/*ascii_is_decimal_digit*/(u64 A_002E5/*c*/);
static u64 A_002E8/*ascii_is_uppercase_hexadecimal_digit*/(u64 A_002E7/*c*/);
static void A_002EB/*debug_assert*/(u8 (*A_002E9/*dbgpos*/), u32 A_002EA/*_true*/);
static void A_002EE/*resource_assert*/(u8 (*A_002EC/*dbgpos*/), u32 A_002ED/*_true*/);
static void A_002F1/*error_assert*/(u8 (*A_002EF/*dbgpos*/), u32 A_002F0/*_true*/);
static s64 A_002F5/*arena_print_bytes*/(A_00001 (*A_002F2/*arena*/), s64 A_002F3/*size*/, void (*A_002F4/*data*/));
static s64 A_002F8/*arena_print_cstring*/(A_00001 (*A_002F6/*arena*/), u8 (*A_002F7/*cstring*/));
static s64 A_002FC/*arena_print_row*/(A_00001 (*A_002F9/*arena*/), s64 A_002FA/*size*/, u32 A_002FB/*ch*/);
static s64 A_00302/*arena_print_u64*/(A_00001 (*A_002FE/*arena*/), u64 A_002FF/*number*/, u64 A_00300/*base*/, s64 A_00301/*min_length*/);
static s64 A_0030D/*arena_print_s64*/(A_00001 (*A_00309/*arena*/), s64 A_0030A/*number*/, u64 A_0030B/*base*/, s64 A_0030C/*min_length*/);
static s64 A_00311/*arena_print_cyechar*/(A_00001 (*A_0030F/*arena*/), u64 A_00310/*cyechar*/);
static A_00001 (*A_00317/*arena_create*/(s64 A_00316/*min_reserved*/));
static void (*A_00321/*arena_get_top*/(A_00001 (*A_00320/*arena*/)));
static void (*A_00324/*arena_push_uninited*/(A_00001 (*A_00322/*arena*/), s64 A_00323/*size*/));
static void (*A_0032B/*arena_push*/(A_00001 (*A_00329/*arena*/), s64 A_0032A/*size*/));
static void A_0032F/*arena_push_aligner*/(A_00001 (*A_0032D/*arena*/), s64 A_0032E/*alignment*/);
static void (*A_00334/*arena_push_copy*/(A_00001 (*A_00331/*arena*/), s64 A_00332/*size*/, void (*A_00333/*data*/)));
static void A_00338/*arena_pop_to_pointer*/(A_00001 (*A_00336/*arena*/), void (*A_00337/*pointer*/));
static u32 A_0033C/*system_memory_commit*/(s64 A_0033A/*size*/, void (*A_0033B/*base*/));
static void (*A_0033F/*system_memory_reserve*/(s64 A_0033E/*size*/));
static void (*A_00341/*get_w_stderr*/(void));
static void A_00344/*say_and_die*/(u8 (*A_00342/*msg*/), u8 (*A_00343/*dbgpos*/));
static u8 (*(*A_00348/*command_get_arguments*/(A_00001 (*A_00346/*result_arena*/), A_00001 (*A_00347/*temp_arena*/))));
static void (*A_00354/*file_read_all_bytes*/(u8 (*A_00352/*cpath*/), A_00001 (*A_00353/*result_arena*/)));
static u32 A_00361/*file_write_all_bytes*/(u8 (*A_0035E/*cpath*/), s64 A_0035F/*size*/, void (*A_00360/*data*/));
static void A_00367/*process_exit*/(u32 A_00366/*status*/);
static void A_0036A/*console_error_print_bytes*/(s64 A_00368/*size*/, void (*A_00369/*data*/));
static void A_0036C/*console_error_print_cstring*/(u8 (*A_0036B/*cstring*/));
static void A_0036D/*console_init*/(void);
static void (*A_00371/*w_stderr*/);
extern s32 GetConsoleMode/*w_GetConsoleMode*/(void (*A_00372/*console_handle*/), u32 (*A_00373/*mode_flags_out*/));
extern s32 SetConsoleMode/*w_SetConsoleMode*/(void (*A_00375/*console_handle*/), u32 A_00376/*mode_flags*/);
extern void (*GetStdHandle/*w_GetStdHandle*/(s32 A_00378/*std_handle*/));
extern s32 WriteFile/*w_WriteFile*/(void (*A_0037A/*file_handle*/), void (*A_0037B/*data*/), u32 A_0037C/*size*/, u32 (*A_0037D/*size_out_opt*/), void (*A_0037E/*overlapped_in_out_opt*/));
extern void ExitProcess/*w_ExitProcess*/(u32 A_00380/*status*/);
extern u8 (*GetCommandLineA/*w_GetCommandLineA*/(void));
extern s32 ReadFile/*w_ReadFile*/(void (*A_00383/*file_handle*/), void (*A_00384/*data_out*/), u32 A_00385/*size*/, u32 (*A_00386/*size_out*/), void (*A_00387/*overlapped_in_out_opt*/));
extern void (*VirtualAlloc/*w_VirtualAlloc*/(void (*A_00389/*base*/), u64 A_0038A/*size*/, u32 A_0038B/*allocation_flags*/, u32 A_0038C/*protect_flags*/));
extern void (*CreateFileA/*w_CreateFileA*/(u8 (*A_0038E/*cpath*/), u32 A_0038F/*access*/, u32 A_00390/*share*/, void (*A_00391/*security_opt*/), u32 A_00392/*disposition*/, u32 A_00393/*flags*/, void (*A_00394/*template_opt*/)));
extern s32 CloseHandle/*w_CloseHandle*/(void (*A_00396/*handle*/));
extern u32 GetFileSize/*w_GetFileSize*/(void (*A_00398/*file_handle*/), u32 (*A_00399/*size_most_significant_part_out_opt*/));


void A_00103/*main*/(void)
{
  u8 (*A_00104/*input_path*/) = NULL;
  u8 (*A_00105/*output_path*/) = NULL;
  A_00038 (*A_0010B/*root*/) = NULL;
  A_00001 (*A_0010C/*output_arena*/) = NULL;
  u32 A_0010D/*ok_1*/ = 0;

  (A_0036D)();
  (A_000FB) = ((s64)0x1);
  (A_000F8) = ((A_00317)(((((s64)0x400) * ((s64)0x400)) * ((s64)0x400))));
  (A_000F9) = ((A_00317)(((((s64)0x400) * ((s64)0x400)) * ((s64)0x400))));
  (A_00104) = ((u8 *)"\x61\x2E\x63\x79\x65");
  (A_00105) = ((u8 *)"\x61\x2E\x63");
  {
    s64 A_00106/*num_input_files*/ = 0;
    u8 (*(*A_00107/*argument_array*/)) = NULL;

    (A_00107) = ((A_00348)((A_000F8), (A_000F9)));
    {
      s64 A_00108/*argument_index*/ = 0;
      for (; ((A_00107)[A_00108]) != (NULL); (A_00108) += ((s64)0x1))
      {
        u8 (*A_00109/*argument*/) = NULL;
        s64 A_0010A/*length*/ = 0;

        (A_00109) = ((A_00107)[A_00108]);
        (A_0010A) = ((A_002D9)((A_00109)));
        if (((A_0010A) == ((s64)0x2)) && ((A_002D1)((A_00109), ((u8 *)"\x2D\x6F"), (A_0010A))))
        {
          (A_002F1)(((u8 *)"\x33\x39\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x67\x75\x6D\x65\x6E\x74\x5F\x61\x72\x72\x61\x79\x5B\x61\x72\x67\x75\x6D\x65\x6E\x74\x5F\x69\x6E\x64\x65\x78\x20\x2B\x20\x31\x5D\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00107)[(A_00108) + ((s64)0x1)]) != (NULL)));
          (A_00108) += ((s64)0x1);
          (A_00105) = ((A_00107)[A_00108]);
        }
        else
        {
          (A_00104) = (A_00109);
          (A_00106) += ((s64)0x1);
          (A_002F1)(((u8 *)"\x34\x30\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6E\x75\x6D\x5F\x69\x6E\x70\x75\x74\x5F\x66\x69\x6C\x65\x73\x20\x3C\x3D\x20\x31\x29\x3B"), ((A_00106) <= ((s64)0x1)));
        }
      }
    }
  }
  if ((s64)0x0)
  {
    (A_0036C)(((u8 *)"\x20\x20\x54\x41\x53\x4B\x3A\x0A\x69\x6E\x70\x75\x74\x3A\x20"));
    (A_0036C)((A_00104));
    (A_0036C)(((u8 *)"\x0A\x6F\x75\x74\x70\x75\x74\x3A\x20"));
    (A_0036C)((A_00105));
    (A_0036C)(((u8 *)"\x0A\x0A"));
  }
  ((A_000FC).A_0000E) = ((s64)0x1);
  ((A_000FD).A_0000E) = ((s64)0x5);
  ((A_000FE).A_0000E) = ((s64)0x6);
  ((A_000FF).A_0000E) = ((s64)0x8);
  ((A_00100).A_0000E) = ((s64)0x9);
  ((A_00101).A_0000E) = ((s64)0xA);
  ((A_00101).A_00013) = (&(A_00100));
  ((A_00102).A_0000E) = ((s64)0xA);
  ((A_00102).A_00013) = (&(A_000FF));
  (A_0010B) = ((A_0019E)((A_00104)));
  (A_0010C) = ((A_00317)(((((s64)0x400) * ((s64)0x400)) * ((s64)0x400))));
  (A_00141)((A_0010B), (A_0010C));
  (A_0010D) = ((A_00361)((A_00105), ((A_0010C)->A_00003), ((A_0010C)->A_00002)));
  (A_002EE)(((u8 *)"\x34\x34\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x72\x65\x73\x6F\x75\x72\x63\x65\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6F\x6B\x5F\x31\x29\x3B"), (A_0010D));
  (A_0036C)(((u8 *)"\x53\x55\x43\x43\x45\x53\x53\x21\x0A"));
}

s64 A_0010F/*type_alignment_of*/(A_0000D (*A_0010E/*type*/))
{
  s64 A_00110/*the_kind*/ = 0;

  (A_002EB)(((u8 *)"\x34\x34\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x74\x79\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0010E) != (NULL)));
  (A_00110) = ((A_0010E)->A_0000E);
  if ((A_00110) == ((s64)0xA))
  {
    return (s64)0x8;
  }
  if (((A_00110) == ((s64)0x5)) || ((A_00110) == ((s64)0x1)))
  {
    return (s64)0x8;
  }
  if (((A_00110) == ((s64)0x6)) || ((A_00110) == ((s64)0x2)))
  {
    return (s64)0x4;
  }
  if (((A_00110) == ((s64)0x7)) || ((A_00110) == ((s64)0x3)))
  {
    return (s64)0x2;
  }
  if (((A_00110) == ((s64)0x8)) || ((A_00110) == ((s64)0x4)))
  {
    return (s64)0x1;
  }
  if ((A_00110) == ((s64)0xC))
  {
    s64 A_00111/*struct_alignment*/ = 0;

    (A_00111) = ((s64)0x1);
    {
      s64 A_00112/*i*/ = 0;
      for (; (A_00112) < ((A_0010E)->A_00016); (A_00112) += ((s64)0x1))
      {
        A_0000D (*A_00113/*member*/) = NULL;
        s64 A_00114/*member_alignment*/ = 0;

        (A_00113) = (((A_0010E)->A_00017)[A_00112]);
        (A_00114) = ((A_0010F)((A_00113)));
        if ((A_00114) > (A_00111))
        {
          (A_00111) = (A_00114);
        }
      }
    }
    return A_00111;
  }
  if ((A_0010E)->A_0000F)
  {
    (A_00293)(((s64)0x0), ((A_0010E)->A_0000F), ((u8 *)"\x63\x61\x6E\x27\x74\x20\x63\x6F\x6D\x70\x75\x74\x65\x20\x74\x79\x70\x65\x5F\x61\x6C\x69\x67\x6E\x6D\x65\x6E\x74\x5F\x6F\x66"));
  }
  (A_002EB)(((u8 *)"\x34\x37\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x30\x29\x3B"), (u32)((s64)0x0));
  return (s64)0x0;
}

s64 A_00116/*type_size_of*/(A_0000D (*A_00115/*type*/))
{
  s64 A_00117/*the_kind*/ = 0;

  (A_002EB)(((u8 *)"\x34\x38\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x74\x79\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00115) != (NULL)));
  (A_00117) = ((A_00115)->A_0000E);
  if ((A_00117) == ((s64)0xA))
  {
    return (s64)0x8;
  }
  if (((A_00117) == ((s64)0x5)) || ((A_00117) == ((s64)0x1)))
  {
    return (s64)0x8;
  }
  if (((A_00117) == ((s64)0x6)) || ((A_00117) == ((s64)0x2)))
  {
    return (s64)0x4;
  }
  if (((A_00117) == ((s64)0x7)) || ((A_00117) == ((s64)0x3)))
  {
    return (s64)0x2;
  }
  if (((A_00117) == ((s64)0x8)) || ((A_00117) == ((s64)0x4)))
  {
    return (s64)0x1;
  }
  if ((A_00117) == ((s64)0xC))
  {
    s64 A_00118/*struct_size*/ = 0;
    s64 A_00119/*struct_alignment*/ = 0;

    (A_00119) = ((s64)0x1);
    {
      s64 A_0011A/*i*/ = 0;
      for (; (A_0011A) < ((A_00115)->A_00016); (A_0011A) += ((s64)0x1))
      {
        A_0000D (*A_0011B/*member*/) = NULL;
        s64 A_0011C/*member_alignment*/ = 0;

        (A_0011B) = (((A_00115)->A_00017)[A_0011A]);
        (A_0011C) = ((A_0010F)((A_0011B)));
        if ((A_0011C) > (A_00119))
        {
          (A_00119) = (A_0011C);
        }
        (A_00118) = ((A_002AF)((A_00118), (A_0011C)));
        (A_00118) += ((A_00116)((A_0011B)));
      }
    }
    (A_00118) = ((A_002AF)((A_00118), (A_00119)));
    return A_00118;
  }
  if ((A_00115)->A_0000F)
  {
    (A_00293)(((s64)0x0), ((A_00115)->A_0000F), ((u8 *)"\x63\x61\x6E\x27\x74\x20\x63\x6F\x6D\x70\x75\x74\x65\x20\x74\x79\x70\x65\x5F\x73\x69\x7A\x65\x5F\x6F\x66"));
  }
  (A_002EB)(((u8 *)"\x35\x31\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x30\x29\x3B"), (u32)((s64)0x0));
  return (s64)0x0;
}

u64 A_0011F/*type_explicit_cast_is_possible*/(A_0000D (*A_0011D/*dst*/), A_0000D (*A_0011E/*src*/))
{
  (void) A_0011E;

  if ((((A_0011D)->A_0000E) == ((s64)0xB)) || (((A_0011D)->A_0000E) == ((s64)0xC)))
  {
    return (s64)0x0;
  }
  return (s64)0x1;
}

s64 A_00123/*bytes_from_extended_text*/(s64 A_00120/*length*/, u8 (*A_00121/*text*/), A_00001 (*A_00122/*result_arena*/))
{
  s64 A_00124/*size*/ = 0;

  {
    s64 A_00125/*ti*/ = 0;
    for (; (A_00125) < (A_00120); (A_00125) += ((s64)0x1))
    {
      u8 A_00126/*byte_value*/ = 0;

      if (((A_00121)[A_00125]) == ((s64)0x5C))
      {
        (A_00125) += ((s64)0x1);
        (A_002EB)(((u8 *)"\x35\x33\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x74\x69\x20\x3C\x20\x6C\x65\x6E\x67\x74\x68\x29\x3B"), ((A_00125) < (A_00120)));
        if (((A_00121)[A_00125]) == ((s64)0x5C))
        {
          (A_00126) = ((s64)0x5C);
        }
        else if (((A_00121)[A_00125]) == ((s64)0x22))
        {
          (A_00126) = ((s64)0x22);
        }
        else if (((A_00121)[A_00125]) == ((s64)0x27))
        {
          (A_00126) = ((s64)0x27);
        }
        else if (((A_00121)[A_00125]) == ((s64)0x60))
        {
          (A_00126) = ((s64)0x60);
        }
        else if (((A_00121)[A_00125]) == ((s64)0x6E))
        {
          (A_00126) = ((s64)0xA);
        }
        else
        {
          u64 A_00127/*d0*/ = 0;
          u64 A_00128/*d1*/ = 0;

          (A_002EB)(((u8 *)"\x35\x34\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x73\x63\x69\x69\x5F\x69\x73\x5F\x75\x70\x70\x65\x72\x63\x61\x73\x65\x5F\x68\x65\x78\x61\x64\x65\x63\x69\x6D\x61\x6C\x5F\x64\x69\x67\x69\x74\x28\x74\x65\x78\x74\x5B\x74\x69\x5D\x29\x29\x3B"), (u32)((A_002E8)(((A_00121)[A_00125]))));
          if ((((A_00125) + ((s64)0x1)) < (A_00120)) && ((A_002E8)(((A_00121)[(A_00125) + ((s64)0x1)]))))
          {
            (A_00127) = ((A_002DE)(((A_00121)[(A_00125) + ((s64)0x0)])));
            (A_00128) = ((A_002DE)(((A_00121)[(A_00125) + ((s64)0x1)])));
            (A_00125) += ((s64)0x1);
          }
          else
          {
            (A_00128) = ((A_002DE)(((A_00121)[(A_00125) + ((s64)0x0)])));
          }
          (A_002EB)(((u8 *)"\x35\x36\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x64\x30\x20\x3C\x20\x31\x36\x29\x3B"), ((A_00127) < ((s64)0x10)));
          (A_002EB)(((u8 *)"\x35\x36\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x64\x31\x20\x3C\x20\x31\x36\x29\x3B"), ((A_00128) < ((s64)0x10)));
          (A_00126) = (((A_00127) << ((s64)0x4)) | (A_00128));
        }
      }
      else
      {
        (A_00126) = ((A_00121)[A_00125]);
      }
      (A_00334)((A_00122), ((s64)0x1), (&(A_00126)));
      (A_00124) += ((s64)0x1);
    }
  }
  return A_00124;
}

u8 (*A_0012C/*declaration_from_type_and_center*/(A_0000D (*A_00129/*type*/), u8 (*A_0012A/*center*/), A_00001 (*A_0012B/*cstring_arena*/)))
{
  u8 (*A_0012D/*result*/) = NULL;
  s64 A_0012E/*type_kind*/ = 0;
  u8 (*A_0012F/*simple_type_c_string*/) = NULL;

  (A_0012E) = ((A_00129)->A_0000E);
  if ((A_0012E) == ((s64)0x5))
  {
    (A_0012F) = ((u8 *)"\x75\x36\x34");
  }
  else if ((A_0012E) == ((s64)0x6))
  {
    (A_0012F) = ((u8 *)"\x75\x33\x32");
  }
  else if ((A_0012E) == ((s64)0x7))
  {
    (A_0012F) = ((u8 *)"\x75\x31\x36");
  }
  else if ((A_0012E) == ((s64)0x8))
  {
    (A_0012F) = ((u8 *)"\x75\x38");
  }
  else if ((A_0012E) == ((s64)0x1))
  {
    (A_0012F) = ((u8 *)"\x73\x36\x34");
  }
  else if ((A_0012E) == ((s64)0x2))
  {
    (A_0012F) = ((u8 *)"\x73\x33\x32");
  }
  else if ((A_0012E) == ((s64)0x3))
  {
    (A_0012F) = ((u8 *)"\x73\x31\x36");
  }
  else if ((A_0012E) == ((s64)0x4))
  {
    (A_0012F) = ((u8 *)"\x73\x38");
  }
  else if ((A_0012E) == ((s64)0x9))
  {
    (A_0012F) = ((u8 *)"\x76\x6F\x69\x64");
  }
  if (A_0012F)
  {
    (A_0012D) = ((A_00321)((A_0012B)));
    (A_002F8)((A_0012B), (A_0012F));
    (A_002F8)((A_0012B), ((u8 *)"\x20"));
    (A_002F8)((A_0012B), (A_0012A));
    (A_0032B)((A_0012B), ((s64)0x1));
  }
  else if ((A_0012E) == ((s64)0xA))
  {
    u8 (*A_00130/*new_center*/) = NULL;

    (A_00130) = ((A_00321)((A_0012B)));
    (A_002F8)((A_0012B), ((u8 *)"\x28\x2A"));
    (A_002F8)((A_0012B), (A_0012A));
    (A_002F8)((A_0012B), ((u8 *)"\x29"));
    (A_0032B)((A_0012B), ((s64)0x1));
    (A_0012D) = ((A_0012C)(((A_00129)->A_00013), (A_00130), (A_0012B)));
  }
  else if ((A_0012E) == ((s64)0xB))
  {
    u8 (*A_00131/*list*/) = NULL;
    u8 (*A_00137/*new_center*/) = NULL;

    {
      s64 A_00132/*i*/ = 0;
      for (; (A_00132) < ((A_00129)->A_00014); (A_00132) += ((s64)0x1))
      {
        A_0000D (*A_00133/*param_type*/) = NULL;
        u8 (*A_00134/*param_center*/) = NULL;
        u8 (*A_00135/*param_declaration*/) = NULL;
        u8 (*A_00136/*new_list*/) = NULL;

        (A_00133) = (((A_00129)->A_00015)[A_00132]);
        (A_00134) = ((u8 *)"");
        if ((A_00133)->A_00010)
        {
          (A_00134) = ((A_00321)((A_0012B)));
          (A_002EB)(((u8 *)"\x36\x32\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x70\x61\x72\x61\x6D\x5F\x74\x79\x70\x65\x2E\x63\x5F\x6E\x61\x6D\x65\x5F\x6F\x70\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00133)->A_00011) != (NULL)));
          (A_002F8)((A_0012B), ((A_00133)->A_00011));
          if (A_000FB)
          {
            (A_002F8)((A_0012B), ((u8 *)"\x2F\x2A"));
            (A_002F5)((A_0012B), (((A_00133)->A_00010)->A_00009), (((A_00133)->A_00010)->A_00008));
            (A_002F8)((A_0012B), ((u8 *)"\x2A\x2F"));
          }
          (A_0032B)((A_0012B), ((s64)0x1));
        }
        (A_00135) = ((A_0012C)((A_00133), (A_00134), (A_0012B)));
        (A_00136) = ((A_00321)((A_0012B)));
        if (A_00131)
        {
          (A_002F8)((A_0012B), (A_00131));
          (A_002F8)((A_0012B), ((u8 *)"\x2C\x20"));
        }
        (A_002F8)((A_0012B), (A_00135));
        (A_0032B)((A_0012B), ((s64)0x1));
        (A_00131) = (A_00136);
      }
    }
    (A_00137) = ((A_00321)((A_0012B)));
    (A_002F8)((A_0012B), (A_0012A));
    (A_002F8)((A_0012B), ((u8 *)"\x28"));
    if (A_00131)
    {
      (A_002F8)((A_0012B), (A_00131));
    }
    else
    {
      (A_002F8)((A_0012B), ((u8 *)"\x76\x6F\x69\x64"));
    }
    (A_002F8)((A_0012B), ((u8 *)"\x29"));
    (A_0032B)((A_0012B), ((s64)0x1));
    (A_0012D) = ((A_0012C)(((A_00129)->A_00013), (A_00137), (A_0012B)));
  }
  else if ((A_0012E) == ((s64)0xC))
  {
    (A_0012D) = ((A_00321)((A_0012B)));
    (A_002EB)(((u8 *)"\x36\x37\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x74\x79\x70\x65\x2E\x73\x74\x72\x75\x63\x74\x5F\x63\x5F\x6E\x61\x6D\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00129)->A_00012) != (NULL)));
    (A_002F8)((A_0012B), ((A_00129)->A_00012));
    (A_002F8)((A_0012B), ((u8 *)"\x20"));
    (A_002F8)((A_0012B), (A_0012A));
    (A_0032B)((A_0012B), ((s64)0x1));
  }
  else
  {
    if ((A_00129)->A_0000F)
    {
      (A_00293)(((s64)0x0), ((A_00129)->A_0000F), ((u8 *)"\x63\x61\x6E\x27\x74\x20\x6D\x61\x6B\x65\x20\x74\x68\x65\x20\x64\x65\x63\x6C\x61\x72\x61\x74\x69\x6F\x6E\x20\x66\x72\x6F\x6D\x20\x74\x68\x69\x73"));
    }
    (A_002EB)(((u8 *)"\x36\x37\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x30\x29\x3B"), (u32)((s64)0x0));
  }
  (A_002EB)(((u8 *)"\x36\x38\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0012D) != (NULL)));
  return A_0012D;
}

u8 (*A_0013A/*print_declaration_center_from_symbol*/(A_00019 (*A_00138/*symbol*/), A_00001 (*A_00139/*result_arena*/)))
{
  u8 (*A_0013B/*center*/) = NULL;

  (A_0013B) = ((A_00321)((A_00139)));
  (A_002F8)((A_00139), ((A_00138)->A_0001D));
  if (A_000FB)
  {
    (A_002F8)((A_00139), ((u8 *)"\x2F\x2A"));
    (A_002F5)((A_00139), (((A_00138)->A_0001A)->A_00009), (((A_00138)->A_0001A)->A_00008));
    (A_002F8)((A_00139), ((u8 *)"\x2A\x2F"));
  }
  (A_0032B)((A_00139), ((s64)0x1));
  return A_0013B;
}

void A_0013E/*c89_compile_integer_constant*/(u64 A_0013C/*value*/, A_00001 (*A_0013D/*output_arena*/))
{
  if ((A_0013C) <= ((s64)0xFFFFFFFF))
  {
    (A_002F8)((A_0013D), ((u8 *)"\x28\x73\x36\x34\x29\x30\x78"));
    (A_00302)((A_0013D), (A_0013C), ((s64)0x10), ((s64)0x0));
  }
  else
  {
    (A_002EB)(((u8 *)"\x37\x31\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x30\x29\x3B\x20\x2F\x2F\x20\x49\x20\x64\x6F\x6E\x27\x74\x20\x6E\x65\x65\x64\x20\x69\x74\x20\x66\x6F\x72\x20\x73\x65\x6C\x66\x2D\x68\x6F\x73\x74\x69\x6E\x67"), (u32)((s64)0x0));
  }
}

void A_00141/*c89_backend*/(A_00038 (*A_0013F/*root*/), A_00001 (*A_00140/*output_arena*/))
{
  A_00019 (*A_00142/*main_symbol*/) = NULL;
  s64 A_00143/*num_voided*/ = 0;

  (A_00142) = ((A_00233)((((A_0013F)->A_00044).A_0002E), (((A_0013F)->A_00044).A_0002D), ((s64)0x4), ((u8 *)"\x6D\x61\x69\x6E")));
  if ((A_00142) == (NULL))
  {
    (A_00293)(((s64)0x0), (NULL), ((u8 *)"\x27\x6D\x61\x69\x6E\x27\x20\x66\x75\x6E\x63\x74\x69\x6F\x6E\x20\x6D\x75\x73\x74\x20\x62\x65\x20\x64\x65\x66\x69\x6E\x65\x64"));
  }
  ((A_00142)->A_00022) += ((s64)0x1);
  (A_002F8)((A_00140), ((u8 *)"\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x23\x69\x6E\x63\x6C\x75\x64\x65\x20\x3C\x73\x74\x64\x64\x65\x66\x2E\x68\x3E\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x23\x69\x6E\x63\x6C\x75\x64\x65\x20\x3C\x73\x74\x64\x69\x6E\x74\x2E\x68\x3E\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x74\x79\x70\x65\x64\x65\x66\x20\x75\x69\x6E\x74\x38\x5F\x74\x20\x20\x75\x38\x3B\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x74\x79\x70\x65\x64\x65\x66\x20\x75\x69\x6E\x74\x31\x36\x5F\x74\x20\x75\x31\x36\x3B\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x74\x79\x70\x65\x64\x65\x66\x20\x75\x69\x6E\x74\x33\x32\x5F\x74\x20\x75\x33\x32\x3B\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x74\x79\x70\x65\x64\x65\x66\x20\x75\x69\x6E\x74\x36\x34\x5F\x74\x20\x75\x36\x34\x3B\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x74\x79\x70\x65\x64\x65\x66\x20\x69\x6E\x74\x38\x5F\x74\x20\x20\x20\x73\x38\x3B\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x74\x79\x70\x65\x64\x65\x66\x20\x69\x6E\x74\x31\x36\x5F\x74\x20\x20\x73\x31\x36\x3B\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x74\x79\x70\x65\x64\x65\x66\x20\x69\x6E\x74\x33\x32\x5F\x74\x20\x20\x73\x33\x32\x3B\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x74\x79\x70\x65\x64\x65\x66\x20\x69\x6E\x74\x36\x34\x5F\x74\x20\x20\x73\x36\x34\x3B\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x0A"));
  (A_00178)((A_0013F), ((s64)0x0), (A_00140));
  (A_002F8)((A_00140), ((u8 *)"\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x76\x6F\x69\x64\x20\x5F\x73\x74\x61\x72\x74\x28\x76\x6F\x69\x64\x29\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x7B\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x20\x20\x65\x78\x74\x65\x72\x6E\x20\x76\x6F\x69\x64\x20\x45\x78\x69\x74\x50\x72\x6F\x63\x65\x73\x73\x28\x75\x33\x32\x20\x73\x74\x61\x74\x75\x73\x29\x3B\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x20\x20\x0A"));
  {
    s64 A_00144/*i*/ = 0;
    for (; (A_00144) < (((A_0013F)->A_00044).A_0002E); (A_00144) += ((s64)0x1))
    {
      A_00019 (*A_00145/*symbol*/) = NULL;

      (A_00145) = ((((A_0013F)->A_00044).A_0002D)[A_00144]);
      if ((((A_00145)->A_00022) == ((s64)0x0)) && (((A_00145)->A_00020) == ((s64)0x1)))
      {
        (A_002F8)((A_00140), ((u8 *)"\x20\x20\x28\x76\x6F\x69\x64\x29\x20"));
        (A_002F8)((A_00140), ((A_00145)->A_0001D));
        (A_002F8)((A_00140), ((u8 *)"\x3B\x0A"));
        (A_00143) += ((s64)0x1);
      }
    }
  }
  if ((A_00143) > ((s64)0x0))
  {
    (A_002F8)((A_00140), ((u8 *)"\x20\x20\x0A"));
  }
  (A_002EB)(((u8 *)"\x37\x37\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6D\x61\x69\x6E\x5F\x73\x79\x6D\x62\x6F\x6C\x2E\x74\x79\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00142)->A_0001B) != (NULL)));
  if ((((((A_00142)->A_0001B)->A_0000E) != ((s64)0xB)) || (((((A_00142)->A_0001B)->A_00013)->A_0000E) != ((s64)0x9))) || ((((A_00142)->A_0001B)->A_00014) != ((s64)0x0)))
  {
    (A_00293)(((s64)0x0), ((A_00142)->A_0001A), ((u8 *)"\x27\x6D\x61\x69\x6E\x27\x20\x6D\x75\x73\x74\x20\x62\x65\x20\x61\x20\x66\x75\x6E\x63\x74\x69\x6F\x6E\x20\x6F\x66\x20\x74\x79\x70\x65\x20\x27\x28\x29\x20\x2D\x3E\x20\x76\x6F\x69\x64\x27"));
  }
  (A_002F8)((A_00140), ((u8 *)"\x20\x20"));
  (A_002F8)((A_00140), ((A_00142)->A_0001D));
  (A_002F8)((A_00140), ((u8 *)"\x28\x29\x3B\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x20\x20\x45\x78\x69\x74\x50\x72\x6F\x63\x65\x73\x73\x28\x30\x29\x3B\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x7D\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x0A"));
  (A_002F8)((A_00140), ((u8 *)"\x0A"));
}

void A_00148/*c89_compile_expression_recursively*/(A_00038 (*A_00146/*expr*/), A_00001 (*A_00147/*output_arena*/))
{
  s64 A_00149/*expr_kind*/ = 0;
  u8 (*A_0014A/*binary_cstring*/) = NULL;
  u8 (*A_0014B/*unary_cstring*/) = NULL;

  (A_002EB)(((u8 *)"\x37\x39\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x65\x78\x70\x72\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00146) != (NULL)));
  (A_002EB)(((u8 *)"\x37\x39\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6F\x75\x74\x70\x75\x74\x5F\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00147) != (NULL)));
  (A_00149) = ((A_00146)->A_00039);
  if ((A_00149) == ((s64)0x23))
  {
    (A_0014A) = ((u8 *)"\x2B");
  }
  else if ((A_00149) == ((s64)0x24))
  {
    (A_0014A) = ((u8 *)"\x2D");
  }
  else if ((A_00149) == ((s64)0x25))
  {
    (A_0014A) = ((u8 *)"\x2A");
  }
  else if ((A_00149) == ((s64)0x26))
  {
    (A_0014A) = ((u8 *)"\x2F");
  }
  else if ((A_00149) == ((s64)0x27))
  {
    (A_0014A) = ((u8 *)"\x25");
  }
  else if ((A_00149) == ((s64)0x28))
  {
    (A_0014A) = ((u8 *)"\x26");
  }
  else if ((A_00149) == ((s64)0x29))
  {
    (A_0014A) = ((u8 *)"\x5E");
  }
  else if ((A_00149) == ((s64)0x2A))
  {
    (A_0014A) = ((u8 *)"\x7C");
  }
  else if ((A_00149) == ((s64)0x32))
  {
    (A_0014A) = ((u8 *)"\x3C");
  }
  else if ((A_00149) == ((s64)0x33))
  {
    (A_0014A) = ((u8 *)"\x3E");
  }
  else if ((A_00149) == ((s64)0x37))
  {
    (A_0014A) = ((u8 *)"\x3D");
  }
  else if ((A_00149) == ((s64)0x38))
  {
    (A_0014A) = ((u8 *)"\x2B\x3D");
  }
  else if ((A_00149) == ((s64)0x39))
  {
    (A_0014A) = ((u8 *)"\x2D\x3D");
  }
  else if ((A_00149) == ((s64)0x3A))
  {
    (A_0014A) = ((u8 *)"\x2A\x3D");
  }
  else if ((A_00149) == ((s64)0x3B))
  {
    (A_0014A) = ((u8 *)"\x2F\x3D");
  }
  else if ((A_00149) == ((s64)0x3C))
  {
    (A_0014A) = ((u8 *)"\x25\x3D");
  }
  else if ((A_00149) == ((s64)0x3D))
  {
    (A_0014A) = ((u8 *)"\x26\x3D");
  }
  else if ((A_00149) == ((s64)0x3E))
  {
    (A_0014A) = ((u8 *)"\x5E\x3D");
  }
  else if ((A_00149) == ((s64)0x3F))
  {
    (A_0014A) = ((u8 *)"\x7C\x3D");
  }
  else if ((A_00149) == ((s64)0x30))
  {
    (A_0014A) = ((u8 *)"\x3C\x3D");
  }
  else if ((A_00149) == ((s64)0x31))
  {
    (A_0014A) = ((u8 *)"\x3E\x3D");
  }
  else if ((A_00149) == ((s64)0x2E))
  {
    (A_0014A) = ((u8 *)"\x3D\x3D");
  }
  else if ((A_00149) == ((s64)0x2F))
  {
    (A_0014A) = ((u8 *)"\x21\x3D");
  }
  else if ((A_00149) == ((s64)0x2B))
  {
    (A_0014A) = ((u8 *)"\x3C\x3C");
  }
  else if ((A_00149) == ((s64)0x2C))
  {
    (A_0014A) = ((u8 *)"\x3E\x3E");
  }
  else if ((A_00149) == ((s64)0x40))
  {
    (A_0014A) = ((u8 *)"\x3C\x3C\x3D");
  }
  else if ((A_00149) == ((s64)0x41))
  {
    (A_0014A) = ((u8 *)"\x3E\x3E\x3D");
  }
  else if ((A_00149) == ((s64)0x35))
  {
    (A_0014A) = ((u8 *)"\x26\x26");
  }
  else if ((A_00149) == ((s64)0x36))
  {
    (A_0014A) = ((u8 *)"\x7C\x7C");
  }
  else if ((A_00149) == ((s64)0x19))
  {
    (A_0014B) = ((u8 *)"\x2B");
  }
  else if ((A_00149) == ((s64)0x1A))
  {
    (A_0014B) = ((u8 *)"\x2D");
  }
  else if ((A_00149) == ((s64)0x1B))
  {
    (A_0014B) = ((u8 *)"\x7E");
  }
  else if ((A_00149) == ((s64)0x1D))
  {
    (A_0014B) = ((u8 *)"\x21");
  }
  else if ((A_00149) == ((s64)0x20))
  {
    (A_0014B) = ((u8 *)"\x2A");
  }
  else if ((A_00149) == ((s64)0x21))
  {
    (A_0014B) = ((u8 *)"\x26");
  }
  if (A_0014A)
  {
    (A_002EB)(((u8 *)"\x38\x33\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x65\x78\x70\x72\x2E\x65\x78\x70\x72\x5F\x30\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00146)->A_0003B) != (NULL)));
    (A_002EB)(((u8 *)"\x38\x33\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x65\x78\x70\x72\x2E\x65\x78\x70\x72\x5F\x31\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00146)->A_0003C) != (NULL)));
    (A_002F8)((A_00147), ((u8 *)"\x28"));
    (A_00148)(((A_00146)->A_0003B), (A_00147));
    (A_002F8)((A_00147), ((u8 *)"\x29\x20"));
    (A_002F8)((A_00147), (A_0014A));
    (A_002F8)((A_00147), ((u8 *)"\x20\x28"));
    (A_00148)(((A_00146)->A_0003C), (A_00147));
    (A_002F8)((A_00147), ((u8 *)"\x29"));
  }
  else if (A_0014B)
  {
    (A_002EB)(((u8 *)"\x38\x35\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x65\x78\x70\x72\x2E\x65\x78\x70\x72\x5F\x30\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00146)->A_0003B) != (NULL)));
    (A_002F8)((A_00147), (A_0014B));
    (A_002F8)((A_00147), ((u8 *)"\x28"));
    (A_00148)(((A_00146)->A_0003B), (A_00147));
    (A_002F8)((A_00147), ((u8 *)"\x29"));
  }
  else if ((A_00149) == ((s64)0xA))
  {
    A_00019 (*A_0014C/*symbol*/) = NULL;

    (A_0014C) = ((A_00146)->A_00042);
    (A_002EB)(((u8 *)"\x38\x36\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0014C) != (NULL)));
    if (((A_0014C)->A_00020) != ((s64)0x5))
    {
      (A_002F8)((A_00147), ((A_0014C)->A_0001D));
    }
    else
    {
      (A_0013E)(((A_0014C)->A_00023), (A_00147));
    }
  }
  else if ((A_00149) == ((s64)0x44))
  {
    A_0000D (*A_0014D/*function_type*/) = NULL;

    (A_002F8)((A_00147), ((u8 *)"\x28"));
    (A_00148)(((A_00146)->A_0003B), (A_00147));
    (A_002F8)((A_00147), ((u8 *)"\x29"));
    (A_0014D) = ((((A_00146)->A_0003B)->A_001C7).A_00033);
    if (((A_0014D)->A_0000E) == ((s64)0x1C))
    {
      (A_0014D) = ((A_0014D)->A_00013);
    }
    (A_002F8)((A_00147), ((u8 *)"\x28"));
    {
      s64 A_0014E/*i*/ = 0;
      for (; (A_0014E) < ((A_00146)->A_00040); (A_0014E) += ((s64)0x1))
      {
        A_00038 (*A_0014F/*arg*/) = NULL;
        A_00031 A_00150/*arg_value*/ = {0};
        A_0000D (*A_00151/*param_type*/) = NULL;

        (A_0014F) = (((A_00146)->A_00041)[A_0014E]);
        (A_00150) = ((A_001C8)(((A_0014F)->A_001C7)));
        (A_00151) = (((A_0014D)->A_00015)[A_0014E]);
        if (((A_001C2)(((A_00151)->A_0000E))) && ((A_001C2)((((A_00150).A_00033)->A_0000E))))
        {
          s64 A_00152/*dst_size*/ = 0;
          s64 A_00153/*src_size*/ = 0;

          (A_00152) = ((A_00116)((A_00151)));
          (A_00153) = ((A_00116)(((A_00150).A_00033)));
          if ((A_00152) < (A_00153))
          {
            s64 A_00154/*type_kind*/ = 0;

            (A_002F8)((A_00147), ((u8 *)"\x28"));
            (A_00154) = ((A_00151)->A_0000E);
            if ((A_00154) == ((s64)0x5))
            {
              (A_002F8)((A_00147), ((u8 *)"\x75\x36\x34"));
            }
            else if ((A_00154) == ((s64)0x6))
            {
              (A_002F8)((A_00147), ((u8 *)"\x75\x33\x32"));
            }
            else if ((A_00154) == ((s64)0x7))
            {
              (A_002F8)((A_00147), ((u8 *)"\x75\x31\x36"));
            }
            else if ((A_00154) == ((s64)0x8))
            {
              (A_002F8)((A_00147), ((u8 *)"\x75\x38"));
            }
            else if ((A_00154) == ((s64)0x1))
            {
              (A_002F8)((A_00147), ((u8 *)"\x73\x36\x34"));
            }
            else if ((A_00154) == ((s64)0x2))
            {
              (A_002F8)((A_00147), ((u8 *)"\x73\x33\x32"));
            }
            else if ((A_00154) == ((s64)0x3))
            {
              (A_002F8)((A_00147), ((u8 *)"\x73\x31\x36"));
            }
            else if ((A_00154) == ((s64)0x4))
            {
              (A_002F8)((A_00147), ((u8 *)"\x73\x38"));
            }
            else
            {
              (A_002EB)(((u8 *)"\x39\x30\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x65\x6C\x73\x65\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x30\x29\x3B"), (u32)((s64)0x0));
            }
            (A_002F8)((A_00147), ((u8 *)"\x29"));
          }
        }
        (A_002F8)((A_00147), ((u8 *)"\x28"));
        (A_00148)((A_0014F), (A_00147));
        (A_002F8)((A_00147), ((u8 *)"\x29"));
        if (((A_0014E) + ((s64)0x1)) < ((A_00146)->A_00040))
        {
          (A_002F8)((A_00147), ((u8 *)"\x2C\x20"));
        }
      }
    }
    (A_002F8)((A_00147), ((u8 *)"\x29"));
  }
  else if ((A_00149) == ((s64)0xB))
  {
    (A_002F8)((A_00147), ((u8 *)"\x4E\x55\x4C\x4C"));
  }
  else if ((A_00149) == ((s64)0x18))
  {
    u8 (*A_00155/*bytes*/) = NULL;
    s64 A_00156/*size*/ = 0;

    (A_00155) = ((A_00321)((A_000F9)));
    (A_00156) = ((A_00123)(((((A_00146)->A_0003A)->A_00009) - ((s64)0x2)), ((((A_00146)->A_0003A)->A_00008) + ((s64)0x1)), (A_000F9)));
    (A_002F8)((A_00147), ((u8 *)"\x28\x75\x38\x20\x2A\x29\x22"));
    {
      s64 A_00157/*i*/ = 0;
      for (; (A_00157) < (A_00156); (A_00157) += ((s64)0x1))
      {
        (A_002F8)((A_00147), ((u8 *)"\x5C\x78"));
        (A_00302)((A_00147), ((A_00155)[A_00157]), ((s64)0x10), ((s64)0x2));
      }
    }
    (A_002F8)((A_00147), ((u8 *)"\x22"));
    (A_00338)((A_000F9), (A_00155));
  }
  else if ((A_00149) == ((s64)0x16))
  {
    (A_002EB)(((u8 *)"\x39\x34\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x65\x78\x70\x72\x2E\x76\x61\x6C\x75\x65\x2E\x69\x73\x5F\x63\x6F\x6E\x73\x74\x65\x78\x70\x72\x29\x3B"), (u32)(((A_00146)->A_001C7).A_00036));
    (A_0013E)((((A_00146)->A_001C7).A_00034), (A_00147));
  }
  else if ((A_00149) == ((s64)0x17))
  {
    u8 (*A_00158/*bytes*/) = NULL;
    s64 A_00159/*size*/ = 0;
    u64 A_0015A/*value*/ = 0;

    (A_00158) = ((A_00321)((A_000F9)));
    (A_00159) = ((A_00123)(((((A_00146)->A_0003A)->A_00009) - ((s64)0x2)), ((((A_00146)->A_0003A)->A_00008) + ((s64)0x1)), (A_000F9)));
    {
      s64 A_0015B/*i*/ = 0;
      for (; (A_0015B) < (A_00159); (A_0015B) += ((s64)0x1))
      {
        (A_0015A) *= ((s64)0x100);
        (A_0015A) += ((A_00158)[A_0015B]);
      }
    }
    (A_00338)((A_000F9), (A_00158));
    (A_0013E)((A_0015A), (A_00147));
  }
  else if ((A_00149) == ((s64)0x15))
  {
    u8 (*A_0015C/*bytes*/) = NULL;
    s64 A_0015D/*row*/ = 0;
    s64 A_0015E/*col*/ = 0;
    u8 (*A_0015F/*cp*/) = NULL;
    u8 (*A_00160/*line_at*/) = NULL;
    s64 A_00161/*line_size*/ = 0;
    s64 A_00162/*size*/ = 0;

    (A_0015C) = ((A_00321)((A_000F9)));
    (A_0015D) = ((s64)0x1);
    (A_0015E) = ((s64)0x1);
    (A_0015F) = (((A_00146)->A_0003A)->A_0000B);
    {
      for (; (A_0015F) != (((A_00146)->A_0003A)->A_00008); (A_0015F) += ((s64)0x1))
      {
        if ((*(A_0015F)) == ((s64)0xA))
        {
          (A_0015D) += ((s64)0x1);
          (A_0015E) = ((s64)0x0);
        }
        (A_0015E) += ((s64)0x1);
      }
    }
    (A_00160) = ((((A_00146)->A_0003A)->A_00008) - ((A_0015E) - ((s64)0x1)));
    while ((((A_00160)[A_00161]) != ((s64)0x0)) && (((A_00160)[A_00161]) != ((s64)0xA)))
    {
      (A_00161) += ((s64)0x1);
    }
    (A_0030D)((A_000F9), (A_0015D), ((s64)0xA), ((s64)0x0));
    (A_002F8)((A_000F9), ((u8 *)"\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20"));
    (A_002F5)((A_000F9), (A_00161), (A_00160));
    (A_00162) = (((u8 (*))((A_00321)((A_000F9)))) - (A_0015C));
    (A_002F8)((A_00147), ((u8 *)"\x28\x75\x38\x20\x2A\x29\x22"));
    {
      s64 A_00163/*i*/ = 0;
      for (; (A_00163) < (A_00162); (A_00163) += ((s64)0x1))
      {
        (A_002F8)((A_00147), ((u8 *)"\x5C\x78"));
        (A_00302)((A_00147), ((A_0015C)[A_00163]), ((s64)0x10), ((s64)0x2));
      }
    }
    (A_002F8)((A_00147), ((u8 *)"\x22"));
    (A_00338)((A_000F9), (A_0015C));
  }
  else if ((A_00149) == ((s64)0x1E))
  {
    (A_002EB)(((u8 *)"\x31\x30\x31\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x65\x78\x70\x72\x2E\x76\x61\x6C\x75\x65\x2E\x69\x73\x5F\x63\x6F\x6E\x73\x74\x65\x78\x70\x72\x29\x3B"), (u32)(((A_00146)->A_001C7).A_00036));
    (A_0013E)((((A_00146)->A_001C7).A_00034), (A_00147));
  }
  else if ((A_00149) == ((s64)0x1F))
  {
    (A_002EB)(((u8 *)"\x31\x30\x31\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x65\x78\x70\x72\x2E\x76\x61\x6C\x75\x65\x2E\x69\x73\x5F\x63\x6F\x6E\x73\x74\x65\x78\x70\x72\x29\x3B"), (u32)(((A_00146)->A_001C7).A_00036));
    (A_0013E)((((A_00146)->A_001C7).A_00034), (A_00147));
  }
  else if ((A_00149) == ((s64)0x34))
  {
    (A_002EB)(((u8 *)"\x31\x30\x32\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x65\x78\x70\x72\x2E\x65\x78\x70\x72\x5F\x30\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00146)->A_0003B) != (NULL)));
    (A_002EB)(((u8 *)"\x31\x30\x32\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x65\x78\x70\x72\x2E\x65\x78\x70\x72\x5F\x31\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00146)->A_0003C) != (NULL)));
    (A_002F8)((A_00147), ((u8 *)"\x28"));
    (A_00148)(((A_00146)->A_0003B), (A_00147));
    (A_002F8)((A_00147), ((u8 *)"\x29"));
    (A_002F8)((A_00147), ((u8 *)"\x5B"));
    (A_00148)(((A_00146)->A_0003C), (A_00147));
    (A_002F8)((A_00147), ((u8 *)"\x5D"));
  }
  else if ((A_00149) == ((s64)0x42))
  {
    A_0000D (*A_00164/*dst_type*/) = NULL;
    A_0000D (*A_00165/*src_type*/) = NULL;
    u64 A_00166/*is_fp*/ = 0;
    void (*A_00167/*temp_top*/) = NULL;
    u8 (*A_00168/*ctype_cstring*/) = NULL;

    (A_00164) = (((A_00146)->A_001C7).A_00033);
    (A_00165) = ((((A_00146)->A_0003B)->A_001C7).A_00033);
    (A_00166) = ((((A_00165)->A_0000E) == ((s64)0xA)) && ((((A_00165)->A_00013)->A_0000E) == ((s64)0xB)));
    if ((((A_00165)->A_0000E) == ((s64)0xB)) || (A_00166))
    {
      (A_00293)(((s64)0x0), ((A_00146)->A_0003A), ((u8 *)"\x49\x20\x64\x6F\x6E\x27\x74\x20\x6B\x6E\x6F\x77\x20\x68\x6F\x77\x20\x74\x6F\x20\x64\x6F\x20\x74\x68\x69\x73\x20\x69\x6E\x20\x43\x38\x39\x20\x77\x69\x74\x68\x6F\x75\x74\x20\x77\x61\x72\x6E\x69\x6E\x67\x73"));
    }
    (A_002F8)((A_00147), ((u8 *)"\x28"));
    (A_00167) = ((A_00321)((A_000F9)));
    (A_00168) = ((A_0012C)((A_00164), ((u8 *)""), (A_000F9)));
    (A_002F8)((A_00147), (A_00168));
    (A_00338)((A_000F9), (A_00167));
    (A_002F8)((A_00147), ((u8 *)"\x29"));
    (A_002F8)((A_00147), ((u8 *)"\x28"));
    (A_00148)(((A_00146)->A_0003B), (A_00147));
    (A_002F8)((A_00147), ((u8 *)"\x29"));
  }
  else if ((A_00149) == ((s64)0x2D))
  {
    u8 (*A_00169/*c_member_name*/) = NULL;

    (A_002F8)((A_00147), ((u8 *)"\x28"));
    (A_00148)(((A_00146)->A_0003B), (A_00147));
    (A_002F8)((A_00147), ((u8 *)"\x29"));
    if ((((((A_00146)->A_0003B)->A_001C7).A_00033)->A_0000E) == ((s64)0xA))
    {
      (A_002F8)((A_00147), ((u8 *)"\x2D\x3E"));
    }
    else
    {
      (A_002F8)((A_00147), ((u8 *)"\x2E"));
    }
    (A_00169) = ((((A_00146)->A_001C7).A_00033)->A_00011);
    (A_002EB)(((u8 *)"\x31\x30\x36\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x63\x5F\x6D\x65\x6D\x62\x65\x72\x5F\x6E\x61\x6D\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00169) != (NULL)));
    (A_002F8)((A_00147), (A_00169));
  }
  else
  {
    (A_00293)(((s64)0x0), ((A_00146)->A_0003A), ((u8 *)"\x69\x64\x75\x6E\x6F\x20\x68\x6F\x77\x20\x74\x6F\x20\x63\x6F\x6D\x70\x69\x6C\x65\x20\x74\x68\x69\x73"));
  }
}

void A_0016D/*c89_compile_block*/(A_00038 (*A_0016A/*block_stmt*/), s64 A_0016B/*spaces*/, A_00001 (*A_0016C/*output_arena*/))
{
  if (((A_0016A)->A_00039) == ((s64)0x2))
  {
    (A_00178)((A_0016A), (A_0016B), (A_0016C));
  }
  else
  {
    (A_002FC)((A_0016C), (A_0016B), (u32)((s64)0x20));
    (A_002F8)((A_0016C), ((u8 *)"\x7B\x0A"));
    (A_00178)((A_0016A), ((A_0016B) + ((s64)0x2)), (A_0016C));
    (A_002FC)((A_0016C), (A_0016B), (u32)((s64)0x20));
    (A_002F8)((A_0016C), ((u8 *)"\x7D\x0A"));
  }
}

void A_00171/*c89_compile_local_symbol*/(A_00019 (*A_0016E/*symbol*/), s64 A_0016F/*sub_spaces*/, A_00001 (*A_00170/*output_arena*/))
{
  void (*A_00172/*temp_top*/) = NULL;
  u8 (*A_00173/*center*/) = NULL;
  u8 (*A_00174/*declaration_cstring*/) = NULL;

  (A_002EB)(((u8 *)"\x31\x30\x39\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0016E) != (NULL)));
  (A_002EB)(((u8 *)"\x31\x30\x39\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x74\x79\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_0016E)->A_0001B) != (NULL)));
  (A_002EB)(((u8 *)"\x31\x30\x39\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x73\x74\x6F\x72\x61\x67\x65\x20\x21\x3D\x20\x53\x54\x4F\x52\x41\x47\x45\x5F\x43\x5F\x54\x59\x50\x45\x44\x45\x46\x29\x3B"), (((A_0016E)->A_00020) != ((s64)0x4)));
  (A_002FC)((A_00170), (A_0016F), (u32)((s64)0x20));
  if (((A_0016E)->A_00020) == ((s64)0x2))
  {
    (A_002F8)((A_00170), ((u8 *)"\x65\x78\x74\x65\x72\x6E\x20"));
  }
  else if (((A_0016E)->A_00020) == ((s64)0x1))
  {
    (A_002F8)((A_00170), ((u8 *)"\x73\x74\x61\x74\x69\x63\x20"));
  }
  (A_00172) = ((A_00321)((A_000F9)));
  (A_00173) = ((A_0013A)((A_0016E), (A_000F9)));
  (A_00174) = ((A_0012C)(((A_0016E)->A_0001B), (A_00173), (A_000F9)));
  (A_002F8)((A_00170), (A_00174));
  (A_00338)((A_000F9), (A_00172));
  if (((A_0016E)->A_00020) == ((s64)0x3))
  {
    if ((((A_0016E)->A_0001B)->A_0000E) == ((s64)0xA))
    {
      (A_002F8)((A_00170), ((u8 *)"\x20\x3D\x20\x4E\x55\x4C\x4C"));
    }
    else if ((((A_0016E)->A_0001B)->A_0000E) == ((s64)0xC))
    {
      (A_002F8)((A_00170), ((u8 *)"\x20\x3D\x20\x7B\x30\x7D"));
    }
    else
    {
      (A_002F8)((A_00170), ((u8 *)"\x20\x3D\x20\x30"));
    }
  }
  (A_002F8)((A_00170), ((u8 *)"\x3B\x0A"));
}

void A_00178/*c89_compile_statement_recursively*/(A_00038 (*A_00175/*stmt*/), s64 A_00176/*spaces*/, A_00001 (*A_00177/*output_arena*/))
{
  s64 A_00179/*stmt_kind*/ = 0;

  (A_00179) = ((A_00175)->A_00039);
  if ((A_00179) == ((s64)0x1))
  {
    A_00038 (*A_0017A/*scope_holder*/) = NULL;
    s64 A_0017B/*num_typedefs*/ = 0;
    s64 A_0017E/*num_structs*/ = 0;

    (A_0017A) = (A_00175);
    {
      s64 A_0017C/*i*/ = 0;
      for (; (A_0017C) < (((A_0017A)->A_00044).A_0002E); (A_0017C) += ((s64)0x1))
      {
        A_00019 (*A_0017D/*symbol*/) = NULL;

        (A_0017D) = ((((A_0017A)->A_00044).A_0002D)[A_0017C]);
        (A_002EB)(((u8 *)"\x31\x31\x33\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0017D) != (NULL)));
        (A_002EB)(((u8 *)"\x31\x31\x33\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x74\x79\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_0017D)->A_0001B) != (NULL)));
        if (((A_0017D)->A_00020) == ((s64)0x4))
        {
          (A_002EB)(((u8 *)"\x31\x31\x34\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x74\x79\x70\x65\x2E\x74\x79\x70\x65\x5F\x6B\x69\x6E\x64\x20\x3D\x3D\x20\x54\x59\x50\x45\x5F\x53\x54\x52\x55\x43\x54\x29\x3B"), ((((A_0017D)->A_0001B)->A_0000E) == ((s64)0xC)));
          (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
          (A_002F8)((A_00177), ((u8 *)"\x74\x79\x70\x65\x64\x65\x66\x20\x73\x74\x72\x75\x63\x74\x20"));
          (A_002F8)((A_00177), (((A_0017D)->A_0001B)->A_00012));
          (A_002F8)((A_00177), ((u8 *)"\x20"));
          (A_002F8)((A_00177), (((A_0017D)->A_0001B)->A_00012));
          (A_002F8)((A_00177), ((u8 *)"\x3B\x0A"));
          (A_0017B) += ((s64)0x1);
        }
      }
    }
    if ((A_0017B) > ((s64)0x0))
    {
      (A_002F8)((A_00177), ((u8 *)"\x0A"));
    }
    {
      s64 A_0017F/*i*/ = 0;
      for (; (A_0017F) < (((A_0017A)->A_00044).A_0002E); (A_0017F) += ((s64)0x1))
      {
        A_00019 (*A_00180/*symbol*/) = NULL;

        (A_00180) = ((((A_0017A)->A_00044).A_0002D)[A_0017F]);
        (A_002EB)(((u8 *)"\x31\x31\x36\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00180) != (NULL)));
        (A_002EB)(((u8 *)"\x31\x31\x36\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x74\x79\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00180)->A_0001B) != (NULL)));
        if (((A_00180)->A_00020) == ((s64)0x4))
        {
          s64 A_00181/*sub_spaces*/ = 0;

          (A_002EB)(((u8 *)"\x31\x31\x36\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x74\x79\x70\x65\x2E\x74\x79\x70\x65\x5F\x6B\x69\x6E\x64\x20\x3D\x3D\x20\x54\x59\x50\x45\x5F\x53\x54\x52\x55\x43\x54\x29\x3B"), ((((A_00180)->A_0001B)->A_0000E) == ((s64)0xC)));
          (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
          (A_002F8)((A_00177), ((u8 *)"\x73\x74\x72\x75\x63\x74\x20"));
          (A_002F8)((A_00177), (((A_00180)->A_0001B)->A_00012));
          (A_002F8)((A_00177), ((u8 *)"\x0A"));
          (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
          (A_002F8)((A_00177), ((u8 *)"\x7B\x0A"));
          (A_00181) = ((A_00176) + ((s64)0x2));
          {
            s64 A_00182/*member_index*/ = 0;
            for (; (A_00182) < (((A_00180)->A_0001B)->A_00016); (A_00182) += ((s64)0x1))
            {
              A_0000D (*A_00183/*member_type*/) = NULL;
              void (*A_00184/*temp_top*/) = NULL;
              u8 (*A_00185/*declaration_cstring*/) = NULL;

              (A_00183) = ((((A_00180)->A_0001B)->A_00017)[A_00182]);
              (A_002FC)((A_00177), (A_00181), (u32)((s64)0x20));
              (A_00184) = ((A_00321)((A_000F9)));
              (A_002EB)(((u8 *)"\x31\x31\x38\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6D\x65\x6D\x62\x65\x72\x5F\x74\x79\x70\x65\x2E\x63\x5F\x6E\x61\x6D\x65\x5F\x6F\x70\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00183)->A_00011) != (NULL)));
              (A_00185) = ((A_0012C)((A_00183), ((A_00183)->A_00011), (A_000F9)));
              (A_002F8)((A_00177), (A_00185));
              (A_00338)((A_000F9), (A_00184));
              (A_002F8)((A_00177), ((u8 *)"\x3B\x0A"));
            }
          }
          (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
          (A_002F8)((A_00177), ((u8 *)"\x7D\x3B\x0A"));
          (A_0017E) += ((s64)0x1);
        }
      }
    }
    if ((A_0017E) > ((s64)0x0))
    {
      (A_002F8)((A_00177), ((u8 *)"\x0A"));
    }
    {
      s64 A_00186/*i*/ = 0;
      for (; (A_00186) < ((A_00175)->A_00040); (A_00186) += ((s64)0x1))
      {
        A_00038 (*A_00187/*node*/) = NULL;

        (A_00187) = (((A_00175)->A_00041)[A_00186]);
        if (((A_00187)->A_00039) == ((s64)0x22))
        {
          A_00019 (*A_00188/*symbol*/) = NULL;
          void (*A_00189/*temp_top*/) = NULL;
          u8 (*A_0018A/*center*/) = NULL;
          u8 (*A_0018B/*declaration_cstring*/) = NULL;

          (A_00188) = (((A_00187)->A_0003B)->A_00042);
          (A_002EB)(((u8 *)"\x31\x32\x31\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00188) != (NULL)));
          (A_002EB)(((u8 *)"\x31\x32\x31\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x74\x79\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00188)->A_0001B) != (NULL)));
          if (((A_00188)->A_00020) == ((s64)0x4))
          {
            continue;
          }
          if (((A_00188)->A_00020) == ((s64)0x2))
          {
            (A_002F8)((A_00177), ((u8 *)"\x65\x78\x74\x65\x72\x6E\x20"));
          }
          else if (((A_00188)->A_00020) == ((s64)0x1))
          {
            (A_002F8)((A_00177), ((u8 *)"\x73\x74\x61\x74\x69\x63\x20"));
          }
          (A_00189) = ((A_00321)((A_000F9)));
          (A_0018A) = ((A_0013A)((A_00188), (A_000F9)));
          (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
          (A_0018B) = ((A_0012C)(((A_00188)->A_0001B), (A_0018A), (A_000F9)));
          (A_002F8)((A_00177), (A_0018B));
          (A_00338)((A_000F9), (A_00189));
          (A_002F8)((A_00177), ((u8 *)"\x3B\x0A"));
        }
      }
    }
    (A_002F8)((A_00177), ((u8 *)"\x0A"));
    {
      s64 A_0018C/*i*/ = 0;
      for (; (A_0018C) < ((A_00175)->A_00040); (A_0018C) += ((s64)0x1))
      {
        (A_00178)((((A_00175)->A_00041)[A_0018C]), (A_00176), (A_00177));
      }
    }
  }
  else if ((((A_00179) == ((s64)0x22)) && ((((A_00175)->A_0003C)->A_00039) == ((s64)0x43))) && (((A_00175)->A_0003E) != (NULL)))
  {
    A_00019 (*A_0018D/*symbol*/) = NULL;
    void (*A_0018E/*temp_top*/) = NULL;
    u8 (*A_0018F/*center*/) = NULL;
    u8 (*A_00190/*declaration_cstring*/) = NULL;

    (A_002F8)((A_00177), ((u8 *)"\x0A"));
    (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
    (A_0018D) = (((A_00175)->A_0003B)->A_00042);
    (A_0018E) = ((A_00321)((A_000F9)));
    (A_0018F) = ((A_0013A)((A_0018D), (A_000F9)));
    (A_00190) = ((A_0012C)(((A_0018D)->A_0001B), (A_0018F), (A_000F9)));
    (A_002F8)((A_00177), (A_00190));
    (A_00338)((A_000F9), (A_0018E));
    (A_002F8)((A_00177), ((u8 *)"\x0A"));
    (A_00178)(((A_00175)->A_0003E), (A_00176), (A_00177));
  }
  else if ((A_00179) == ((s64)0x2))
  {
    s64 A_00191/*sub_spaces*/ = 0;
    s64 A_00192/*num_decls*/ = 0;
    s64 A_00195/*num_voided*/ = 0;
    A_00038 (*A_00196/*scope_holder*/) = NULL;

    (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
    (A_002F8)((A_00177), ((u8 *)"\x7B\x0A"));
    (A_00191) = ((A_00176) + ((s64)0x2));
    {
      s64 A_00193/*i*/ = 0;
      for (; (A_00193) < ((A_00175)->A_00040); (A_00193) += ((s64)0x1))
      {
        A_00038 (*A_00194/*sub_node*/) = NULL;

        (A_00194) = (((A_00175)->A_00041)[A_00193]);
        if (((A_00194)->A_00039) == ((s64)0x22))
        {
          (A_00171)((((A_00194)->A_0003B)->A_00042), (A_00191), (A_00177));
          (A_00192) += ((s64)0x1);
        }
      }
    }
    if ((A_00192) > ((s64)0x0))
    {
      (A_002F8)((A_00177), ((u8 *)"\x0A"));
    }
    (A_00196) = (A_00175);
    {
      s64 A_00197/*i*/ = 0;
      for (; (A_00197) < (((A_00196)->A_00044).A_0002E); (A_00197) += ((s64)0x1))
      {
        A_00019 (*A_00198/*symbol*/) = NULL;

        (A_00198) = ((((A_00196)->A_00044).A_0002D)[A_00197]);
        if (((A_00198)->A_00022) == ((s64)0x0))
        {
          (A_002FC)((A_00177), (A_00191), (u32)((s64)0x20));
          (A_002F8)((A_00177), ((u8 *)"\x28\x76\x6F\x69\x64\x29\x20"));
          (A_002F8)((A_00177), ((A_00198)->A_0001D));
          (A_002F8)((A_00177), ((u8 *)"\x3B\x0A"));
          (A_00195) += ((s64)0x1);
        }
      }
    }
    if ((A_00195) > ((s64)0x0))
    {
      (A_002F8)((A_00177), ((u8 *)"\x0A"));
    }
    {
      s64 A_00199/*i*/ = 0;
      for (; (A_00199) < ((A_00175)->A_00040); (A_00199) += ((s64)0x1))
      {
        (A_00178)((((A_00175)->A_00041)[A_00199]), (A_00191), (A_00177));
      }
    }
    (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
    (A_002F8)((A_00177), ((u8 *)"\x7D\x0A"));
  }
  else if ((A_00179) == ((s64)0x6))
  {
    (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
    (A_002F8)((A_00177), ((u8 *)"\x77\x68\x69\x6C\x65\x20\x28"));
    (A_00148)(((A_00175)->A_0003B), (A_00177));
    (A_002F8)((A_00177), ((u8 *)"\x29\x0A"));
    (A_0016D)(((A_00175)->A_0003E), (A_00176), (A_00177));
  }
  else if ((A_00179) == ((s64)0x7))
  {
    (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
    (A_002F8)((A_00177), ((u8 *)"\x64\x6F\x0A"));
    (A_0016D)(((A_00175)->A_0003E), (A_00176), (A_00177));
    (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
    (A_002F8)((A_00177), ((u8 *)"\x77\x68\x69\x6C\x65\x20\x28"));
    (A_00148)(((A_00175)->A_0003B), (A_00177));
    (A_002F8)((A_00177), ((u8 *)"\x29\x3B\x0A"));
  }
  else if ((A_00179) == ((s64)0x8))
  {
    A_00038 (*A_0019A/*next_else*/) = NULL;

    (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
    (A_002F8)((A_00177), ((u8 *)"\x69\x66\x20\x28"));
    (A_00148)(((A_00175)->A_0003B), (A_00177));
    (A_002F8)((A_00177), ((u8 *)"\x29\x0A"));
    (A_0016D)(((A_00175)->A_0003E), (A_00176), (A_00177));
    (A_0019A) = ((A_00175)->A_0003F);
    while (((A_0019A) != (NULL)) && (((A_0019A)->A_00039) == ((s64)0x8)))
    {
      (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
      (A_002F8)((A_00177), ((u8 *)"\x65\x6C\x73\x65\x20\x69\x66\x20\x28"));
      (A_00148)(((A_0019A)->A_0003B), (A_00177));
      (A_002F8)((A_00177), ((u8 *)"\x29\x0A"));
      (A_0016D)(((A_0019A)->A_0003E), (A_00176), (A_00177));
      (A_0019A) = ((A_0019A)->A_0003F);
    }
    if ((A_0019A) != (NULL))
    {
      (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
      (A_002F8)((A_00177), ((u8 *)"\x65\x6C\x73\x65\x0A"));
      (A_0016D)((A_0019A), (A_00176), (A_00177));
    }
  }
  else if ((A_00179) == ((s64)0x9))
  {
    s64 A_0019B/*sub_spaces*/ = 0;

    (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
    (A_002F8)((A_00177), ((u8 *)"\x7B\x0A"));
    (A_0019B) = ((A_00176) + ((s64)0x2));
    if ((A_00175)->A_0003B)
    {
      A_00019 (*A_0019C/*symbol*/) = NULL;

      (A_002EB)(((u8 *)"\x31\x33\x37\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x6D\x74\x2E\x65\x78\x70\x72\x5F\x30\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x3D\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), ((((A_00175)->A_0003B)->A_00039) == ((s64)0x22)));
      (A_0019C) = ((((A_00175)->A_0003B)->A_0003B)->A_00042);
      (A_002EB)(((u8 *)"\x31\x33\x37\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0019C) != (NULL)));
      (A_00171)((A_0019C), (A_0019B), (A_00177));
      if (((A_0019C)->A_00022) == ((s64)0x0))
      {
        (A_002FC)((A_00177), (A_0019B), (u32)((s64)0x20));
        (A_002F8)((A_00177), ((u8 *)"\x28\x76\x6F\x69\x64\x29\x20"));
        (A_002F8)((A_00177), ((A_0019C)->A_0001D));
        (A_002F8)((A_00177), ((u8 *)"\x3B\x0A"));
      }
    }
    (A_002FC)((A_00177), (A_0019B), (u32)((s64)0x20));
    (A_002F8)((A_00177), ((u8 *)"\x66\x6F\x72\x20\x28\x3B"));
    if ((A_00175)->A_0003C)
    {
      (A_002F8)((A_00177), ((u8 *)"\x20"));
      (A_00148)(((A_00175)->A_0003C), (A_00177));
    }
    (A_002F8)((A_00177), ((u8 *)"\x3B"));
    if ((A_00175)->A_0003D)
    {
      (A_002F8)((A_00177), ((u8 *)"\x20"));
      (A_00148)(((A_00175)->A_0003D), (A_00177));
    }
    (A_002F8)((A_00177), ((u8 *)"\x29\x0A"));
    (A_0016D)(((A_00175)->A_0003E), (A_0019B), (A_00177));
    (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
    (A_002F8)((A_00177), ((u8 *)"\x7D\x0A"));
  }
  else if ((A_00179) == ((s64)0x22))
  {
  }
  else if ((A_00179) == ((s64)0x46))
  {
  }
  else if ((A_00179) == ((s64)0x4))
  {
    (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
    (A_002F8)((A_00177), ((u8 *)"\x62\x72\x65\x61\x6B\x3B\x0A"));
  }
  else if ((A_00179) == ((s64)0x5))
  {
    (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
    (A_002F8)((A_00177), ((u8 *)"\x63\x6F\x6E\x74\x69\x6E\x75\x65\x3B\x0A"));
  }
  else if ((A_00179) == ((s64)0x3))
  {
    (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
    (A_002F8)((A_00177), ((u8 *)"\x72\x65\x74\x75\x72\x6E"));
    if ((A_00175)->A_0003B)
    {
      (A_002F8)((A_00177), ((u8 *)"\x20"));
      (A_00148)(((A_00175)->A_0003B), (A_00177));
    }
    (A_002F8)((A_00177), ((u8 *)"\x3B\x0A"));
  }
  else
  {
    (A_002FC)((A_00177), (A_00176), (u32)((s64)0x20));
    (A_00148)((A_00175), (A_00177));
    (A_002F8)((A_00177), ((u8 *)"\x3B\x0A"));
  }
}

A_00038 (*A_0019E/*language_frontend*/(u8 (*A_0019D/*input_path*/)))
{
  u8 (*A_0019F/*input_text*/) = NULL;
  A_00007 (*A_001A0/*input_tokens*/) = NULL;
  s64 A_001A1/*num_input_tokens*/ = 0;
  A_00038 (*A_001B1/*root*/) = NULL;

  {
    (A_0019F) = ((A_00354)((A_0019D), (A_000F8)));
    (A_002F1)(((u8 *)"\x31\x34\x36\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x69\x6E\x70\x75\x74\x5F\x74\x65\x78\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0019F) != (NULL)));
    (A_0032B)((A_000F8), ((s64)0x1));
  }
  if ((s64)0x0)
  {
    (A_0036C)(((u8 *)"\x20\x20\x46\x49\x4C\x45\x3A\x0A"));
    (A_0036C)((A_0019F));
    (A_0036C)(((u8 *)"\x0A"));
  }
  {
    u8 (*A_001A2/*cp*/) = NULL;

    (A_0032F)((A_000F8), ((s64)0x8));
    (A_001A0) = ((A_00321)((A_000F8)));
    (A_001A2) = (A_0019F);
    {
      for (;;)
      {
        u8 (*A_001A3/*token_beg*/) = NULL;
        s64 A_001A4/*token_kind*/ = 0;
        A_00007 (*A_001AC/*token*/) = NULL;

        {
          for (;;)
          {
            while ((A_002E0)((*(A_001A2))))
            {
              (A_001A2) += ((s64)0x1);
            }
            if ((((A_001A2)[(s64)0x0]) == ((s64)0x2F)) && (((A_001A2)[(s64)0x1]) == ((s64)0x2F)))
            {
              while (((*(A_001A2)) != ((s64)0x0)) && ((*(A_001A2)) != ((s64)0xA)))
              {
                (A_001A2) += ((s64)0x1);
              }
            }
            else
            {
              break;
            }
          }
        }
        (A_001A3) = (A_001A2);
        if ((*(A_001A2)) == ((s64)0x0))
        {
          break;
        }
        else if ((A_002E6)((*(A_001A2))))
        {
          (A_001A4) = ((s64)0x1);
          (A_001A2) += ((s64)0x1);
          while (((A_002E4)((*(A_001A2)))) || ((*(A_001A2)) == ((s64)0x5F)))
          {
            (A_001A2) += ((s64)0x1);
          }
        }
        else if (((A_002E2)((*(A_001A2)))) || ((*(A_001A2)) == ((s64)0x5F)))
        {
          s64 A_001A5/*size*/ = 0;

          (A_001A4) = ((s64)0x4);
          (A_001A2) += ((s64)0x1);
          while (((A_002E4)((*(A_001A2)))) || ((*(A_001A2)) == ((s64)0x5F)))
          {
            (A_001A2) += ((s64)0x1);
          }
          (A_001A5) = ((A_001A2) - (A_001A3));
          if ((A_001A5) == ((s64)0x2))
          {
            if ((A_002D1)((A_001A3), ((u8 *)"\x75\x38"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x5);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x73\x38"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x6);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x6F\x72"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x7);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x69\x66"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x8);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x64\x6F"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x9);
            }
          }
          else if ((A_001A5) == ((s64)0x3))
          {
            if ((A_002D1)((A_001A3), ((u8 *)"\x75\x36\x34"), (A_001A5)))
            {
              (A_001A4) = ((s64)0xA);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x75\x33\x32"), (A_001A5)))
            {
              (A_001A4) = ((s64)0xB);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x75\x31\x36"), (A_001A5)))
            {
              (A_001A4) = ((s64)0xC);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x73\x36\x34"), (A_001A5)))
            {
              (A_001A4) = ((s64)0xD);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x73\x33\x32"), (A_001A5)))
            {
              (A_001A4) = ((s64)0xE);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x73\x31\x36"), (A_001A5)))
            {
              (A_001A4) = ((s64)0xF);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x66\x36\x34"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x10);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x66\x33\x32"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x11);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x61\x6E\x64"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x12);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x6E\x6F\x74"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x13);
            }
          }
          else if ((A_001A5) == ((s64)0x4))
          {
            if ((A_002D1)((A_001A3), ((u8 *)"\x76\x6F\x69\x64"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x14);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x6E\x75\x6C\x6C"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x15);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x65\x6C\x73\x65"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x16);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x65\x6E\x75\x6D"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x17);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x63\x61\x73\x74"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x18);
            }
          }
          else if ((A_001A5) == ((s64)0x5))
          {
            if ((A_002D1)((A_001A3), ((u8 *)"\x77\x68\x69\x6C\x65"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x19);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x62\x72\x65\x61\x6B"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x1A);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x75\x6E\x6F\x69\x6E"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x1B);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x63\x5F\x66\x6F\x72"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x1C);
            }
          }
          else if ((A_001A5) == ((s64)0x6))
          {
            if ((A_002D1)((A_001A3), ((u8 *)"\x72\x65\x74\x75\x72\x6E"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x1D);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x63\x5F\x6E\x61\x6D\x65"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x1E);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x73\x74\x72\x75\x63\x74"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x1F);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x63\x5F\x6C\x6F\x61\x64"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x20);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x63\x5F\x65\x6E\x75\x6D"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x21);
            }
          }
          else if ((A_001A5) == ((s64)0x7))
          {
            if ((A_002D1)((A_001A3), ((u8 *)"\x73\x69\x7A\x65\x5F\x6F\x66"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x22);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x74\x79\x70\x65\x5F\x6F\x66"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x23);
            }
          }
          else if ((A_001A5) == ((s64)0x8))
          {
            if ((A_002D1)((A_001A3), ((u8 *)"\x63\x5F\x65\x78\x74\x65\x72\x6E"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x24);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x63\x5F\x73\x74\x72\x69\x6E\x67"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x25);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x63\x6F\x6E\x74\x69\x6E\x75\x65"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x26);
            }
            else if ((A_002D1)((A_001A3), ((u8 *)"\x63\x5F\x64\x62\x67\x70\x6F\x73"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x27);
            }
          }
          else if ((A_001A5) == ((s64)0x9))
          {
            if ((A_002D1)((A_001A3), ((u8 *)"\x63\x5F\x74\x79\x70\x65\x64\x65\x66"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x28);
            }
          }
          else if ((A_001A5) == ((s64)0xC))
          {
            if ((A_002D1)((A_001A3), ((u8 *)"\x61\x6C\x69\x67\x6E\x6D\x65\x6E\x74\x5F\x6F\x66"), (A_001A5)))
            {
              (A_001A4) = ((s64)0x29);
            }
          }
        }
        else if ((((*(A_001A2)) == ((s64)0x22)) || ((*(A_001A2)) == ((s64)0x27))) || ((*(A_001A2)) == ((s64)0x60)))
        {
          u64 A_001A6/*end_quote*/ = 0;
          s64 A_001A7/*num_backslashes*/ = 0;

          if ((*(A_001A2)) == ((s64)0x22))
          {
            (A_001A4) = ((s64)0x2);
          }
          else if ((*(A_001A2)) == ((s64)0x27))
          {
            (A_001A4) = ((s64)0x3);
          }
          else if ((*(A_001A2)) == ((s64)0x60))
          {
            (A_001A4) = ((s64)0x4);
          }
          (A_001A6) = (*(A_001A2));
          (A_001A2) += ((s64)0x1);
          while (!(((*(A_001A2)) == (A_001A6)) && (((A_001A7) % ((s64)0x2)) == ((s64)0x0))))
          {
            (A_002F1)(((u8 *)"\x31\x36\x30\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x63\x70\x2E\x2A\x20\x21\x3D\x20\x27\x5C\x30\x27\x29\x3B"), ((*(A_001A2)) != ((s64)0x0)));
            (A_002F1)(((u8 *)"\x31\x36\x30\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x63\x70\x2E\x2A\x20\x21\x3D\x20\x27\x5C\x6E\x27\x29\x3B"), ((*(A_001A2)) != ((s64)0xA)));
            (A_001A7) = ((s64)0x0);
            {
              for (; (*(A_001A2)) == ((s64)0x5C); (A_001A7) += ((s64)0x1))
              {
                (A_001A2) += ((s64)0x1);
              }
            }
            if ((A_001A7) == ((s64)0x0))
            {
              (A_001A2) += ((s64)0x1);
            }
          }
          (A_001A2) += ((s64)0x1);
        }
        else
        {
          u64 A_001A8/*c0*/ = 0;
          u64 A_001A9/*c1*/ = 0;
          u64 A_001AA/*c2*/ = 0;
          s64 A_001AB/*size*/ = 0;

          (A_001A8) = ((A_001A2)[(s64)0x0]);
          (A_001A9) = ((A_001A2)[(s64)0x1]);
          (A_001AA) = ((A_001A2)[(s64)0x2]);
          if ((((A_001A8) == ((s64)0x3C)) && ((A_001A9) == ((s64)0x3C))) && ((A_001AA) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x3);
            (A_001A4) = ((s64)0x2A);
          }
          else if ((((A_001A8) == ((s64)0x3E)) && ((A_001A9) == ((s64)0x3E))) && ((A_001AA) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x3);
            (A_001A4) = ((s64)0x2B);
          }
          else if (((A_001A8) == ((s64)0x2B)) && ((A_001A9) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x2C);
          }
          else if (((A_001A8) == ((s64)0x2D)) && ((A_001A9) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x2D);
          }
          else if (((A_001A8) == ((s64)0x2A)) && ((A_001A9) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x2E);
          }
          else if (((A_001A8) == ((s64)0x2F)) && ((A_001A9) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x2F);
          }
          else if (((A_001A8) == ((s64)0x25)) && ((A_001A9) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x30);
          }
          else if (((A_001A8) == ((s64)0x26)) && ((A_001A9) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x31);
          }
          else if (((A_001A8) == ((s64)0x5E)) && ((A_001A9) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x32);
          }
          else if (((A_001A8) == ((s64)0x7C)) && ((A_001A9) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x33);
          }
          else if (((A_001A8) == ((s64)0x3C)) && ((A_001A9) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x34);
          }
          else if (((A_001A8) == ((s64)0x3E)) && ((A_001A9) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x35);
          }
          else if (((A_001A8) == ((s64)0x3D)) && ((A_001A9) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x36);
          }
          else if (((A_001A8) == ((s64)0x21)) && ((A_001A9) == ((s64)0x3D)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x37);
          }
          else if (((A_001A8) == ((s64)0x3C)) && ((A_001A9) == ((s64)0x3C)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x38);
          }
          else if (((A_001A8) == ((s64)0x3E)) && ((A_001A9) == ((s64)0x3E)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x39);
          }
          else if (((A_001A8) == ((s64)0x2D)) && ((A_001A9) == ((s64)0x3E)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x3A);
          }
          else if (((A_001A8) == ((s64)0x2E)) && ((A_001A9) == ((s64)0x2A)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x3B);
          }
          else if (((A_001A8) == ((s64)0x2E)) && ((A_001A9) == ((s64)0x26)))
          {
            (A_001AB) = ((s64)0x2);
            (A_001A4) = ((s64)0x3C);
          }
          else if ((A_001A8) == ((s64)0x2B))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x3D);
          }
          else if ((A_001A8) == ((s64)0x2D))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x3E);
          }
          else if ((A_001A8) == ((s64)0x2A))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x3F);
          }
          else if ((A_001A8) == ((s64)0x2F))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x40);
          }
          else if ((A_001A8) == ((s64)0x25))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x41);
          }
          else if ((A_001A8) == ((s64)0x26))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x42);
          }
          else if ((A_001A8) == ((s64)0x5E))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x43);
          }
          else if ((A_001A8) == ((s64)0x7C))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x44);
          }
          else if ((A_001A8) == ((s64)0x3C))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x45);
          }
          else if ((A_001A8) == ((s64)0x3E))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x46);
          }
          else if ((A_001A8) == ((s64)0x3D))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x47);
          }
          else if ((A_001A8) == ((s64)0x3B))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x48);
          }
          else if ((A_001A8) == ((s64)0x2E))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x49);
          }
          else if ((A_001A8) == ((s64)0x3A))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x4A);
          }
          else if ((A_001A8) == ((s64)0x2C))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x4B);
          }
          else if ((A_001A8) == ((s64)0x28))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x4C);
          }
          else if ((A_001A8) == ((s64)0x29))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x4D);
          }
          else if ((A_001A8) == ((s64)0x7B))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x4E);
          }
          else if ((A_001A8) == ((s64)0x7D))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x4F);
          }
          else if ((A_001A8) == ((s64)0x5B))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x50);
          }
          else if ((A_001A8) == ((s64)0x5D))
          {
            (A_001AB) = ((s64)0x1);
            (A_001A4) = ((s64)0x51);
          }
          (A_002F1)(((u8 *)"\x31\x36\x36\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x21\x3D\x20\x30\x29\x3B"), ((A_001AB) != ((s64)0x0)));
          (A_001A2) += (A_001AB);
        }
        (A_002EB)(((u8 *)"\x31\x36\x37\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x74\x6F\x6B\x65\x6E\x5F\x6B\x69\x6E\x64\x20\x21\x3D\x20\x30\x29\x3B"), ((A_001A4) != ((s64)0x0)));
        (A_001AC) = ((A_0032B)((A_000F8), ((s64)0x20)));
        ((A_001AC)->A_00008) = (A_001A3);
        ((A_001AC)->A_00009) = ((A_001A2) - (A_001A3));
        ((A_001AC)->A_0000A) = (A_001A4);
        ((A_001AC)->A_0000B) = (A_0019F);
        (A_001A1) += ((s64)0x1);
      }
    }
  }
  if ((s64)0x0)
  {
    s64 A_001AD/*line_length*/ = 0;

    (A_0036C)(((u8 *)"\x20\x20\x54\x4F\x4B\x45\x4E\x53\x3A\x0A"));
    {
      s64 A_001AE/*i*/ = 0;
      for (; (A_001AE) < (A_001A1); (A_001AE) += ((s64)0x1))
      {
        A_00007 (*A_001AF/*ith_token*/) = NULL;
        s64 A_001B0/*size*/ = 0;

        (A_001AF) = ((A_001A0) + (A_001AE));
        (A_001B0) = ((((s64)0x1) + ((A_001AF)->A_00009)) + ((s64)0x3));
        if (((A_001AD) + (A_001B0)) > ((s64)0x64))
        {
          (A_0036C)(((u8 *)"\x0A"));
          (A_001AD) = ((s64)0x0);
        }
        (A_0036C)(((u8 *)"\x27"));
        (A_0036A)(((A_001AF)->A_00009), ((A_001AF)->A_00008));
        (A_0036C)(((u8 *)"\x27\x20\x20"));
        (A_001AD) += (A_001B0);
      }
    }
    (A_0036C)(((u8 *)"\x0A\x0A"));
  }
  {
    A_00025 A_001B2/*_parser*/ = {0};
    A_00025 (*A_001B3/*parser*/) = NULL;
    void (*A_001B5/*items_base*/) = NULL;

    (A_001B3) = (&(A_001B2));
    ((A_001B3)->A_00028) = (A_001A0);
    ((A_001B3)->A_00029) = (A_001A1);
    (A_002F1)(((u8 *)"\x31\x37\x31\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x69\x6E\x70\x75\x74\x5F\x74\x65\x78\x74\x5B\x30\x5D\x20\x21\x3D\x20\x27\x5C\x30\x27\x29\x3B"), (((A_0019F)[(s64)0x0]) != ((s64)0x0)));
    (A_0032F)((A_000F8), ((s64)0x8));
    ((A_001B3)->A_00026) = ((A_0032B)((A_000F8), ((s64)0x20)));
    (((A_001B3)->A_00026)->A_0000B) = (A_0019F);
    (((A_001B3)->A_00026)->A_00008) = (A_0019F);
    (((A_001B3)->A_00026)->A_0000A) = ((s64)0x0);
    (((A_001B3)->A_00026)->A_00009) = ((s64)0x0);
    ((A_001B3)->A_00027) = ((A_0032B)((A_000F8), ((s64)0x20)));
    (((A_001B3)->A_00027)->A_0000B) = (A_0019F);
    (((A_001B3)->A_00027)->A_00008) = (A_0019F);
    (((A_001B3)->A_00027)->A_0000A) = ((s64)0x0);
    (((A_001B3)->A_00027)->A_00009) = ((s64)0x0);
    while (((((A_001B3)->A_00027)->A_00008)[(s64)0x1]) != ((s64)0x0))
    {
      (((A_001B3)->A_00027)->A_00008) += ((s64)0x1);
    }
    if ((s64)0x0)
    {
      (A_0036C)(((u8 *)"\x20\x20\x43\x4F\x4D\x50\x4C\x41\x49\x4E\x53\x3A\x0A"));
      {
        s64 A_001B4/*i*/ = 0;
        for (; (A_001B4) < (((A_001B3)->A_00029) + ((s64)0x2)); (A_001B4) += ((s64)0x1))
        {
          (A_00293)(((s64)0x1), ((A_002A8)((A_001B3), ((A_001B4) - ((s64)0x1)))), ((u8 *)"\x74\x68\x69\x73"));
        }
      }
      (A_0036C)(((u8 *)"\x0A"));
    }
    (A_001B1) = ((A_0028E)(((s64)0x1), ((A_001B3)->A_00026)));
    (A_001B5) = ((A_00321)((A_000F9)));
    while (((A_002A1)((A_001B3))) > ((s64)0x0))
    {
      if ((A_00284)((A_001B3), ((s64)0x21)))
      {
        A_00007 (*A_001B6/*c_enum_token*/) = NULL;
        A_00038 (*A_001B7/*global*/) = NULL;

        (A_001B6) = ((A_002A4)((A_001B3), (-((s64)0x1))));
        if (!((A_00280)((A_001B3), ((s64)0x4E))))
        {
          (A_00293)(((s64)0x0), ((A_002A8)((A_001B3), ((s64)0x0))), ((u8 *)"\x65\x78\x70\x65\x63\x74\x65\x64\x20\x74\x68\x65\x20\x6F\x70\x65\x6E\x6E\x69\x6E\x67\x20\x63\x75\x72\x6C\x79\x20\x62\x72\x61\x63\x65\x20\x27\x7B\x27\x20\x61\x66\x74\x65\x72\x20\x63\x5F\x65\x6E\x75\x6D"));
        }
        (A_001B7) = ((A_00278)((A_001B3)));
        ((A_001B7)->A_00039) = ((s64)0x46);
        ((A_001B7)->A_0003A) = (A_001B6);
        {
          s64 A_001B8/*i*/ = 0;
          for (; (A_001B8) < ((A_001B7)->A_00040); (A_001B8) += ((s64)0x1))
          {
            A_00038 (*A_001B9/*node*/) = NULL;
            A_00019 (*A_001BA/*symbol*/) = NULL;

            (A_001B9) = (((A_001B7)->A_00041)[A_001B8]);
            if (((A_001B9)->A_00039) != ((s64)0xA))
            {
              (A_00293)(((s64)0x0), ((A_001B9)->A_0003A), ((u8 *)"\x6E\x6F\x74\x20\x61\x20\x6E\x61\x6D\x65\x20\x69\x6E\x20\x74\x68\x65\x20\x63\x5F\x65\x6E\x75\x6D"));
            }
            (A_0032F)((A_000F8), ((s64)0x8));
            (A_001BA) = ((A_0032B)((A_000F8), ((s64)0x50)));
            ((A_001BA)->A_0001A) = ((A_001B9)->A_0003A);
            ((A_001BA)->A_0001C) = (A_001B9);
            (A_000FA) += ((s64)0x1);
            ((A_001BA)->A_0001D) = ((A_00321)((A_000F8)));
            (A_00276)((A_000F8), (A_000FA));
            (A_0032B)((A_000F8), ((s64)0x1));
            ((A_001B9)->A_00042) = (A_001BA);
          }
        }
        (A_00334)((A_000F9), ((s64)0x8), (&(A_001B7)));
        ((A_001B1)->A_00040) += ((s64)0x1);
      }
      else
      {
        A_00038 (*A_001BB/*global*/) = NULL;

        (A_001BB) = ((A_0024A)((A_001B3), ((s64)0x0)));
        if (((((A_001BB)->A_00039) == ((s64)0x22)) && ((((A_001BB)->A_0003C)->A_00039) == ((s64)0x43))) && ((A_00280)((A_001B3), ((s64)0x4E))))
        {
          ((A_001BB)->A_0003E) = ((A_00278)((A_001B3)));
        }
        else
        {
          (A_00289)((A_001B3), ((s64)0x48), ((u8 *)"\x74\x68\x65\x20\x73\x65\x6D\x69\x63\x6F\x6C\x6F\x6E\x20\x27\x3B\x27\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x67\x6C\x6F\x62\x61\x6C\x20\x64\x65\x63\x6C\x61\x72\x74\x69\x6F\x6E"));
        }
        (A_00334)((A_000F9), ((s64)0x8), (&(A_001BB)));
        ((A_001B1)->A_00040) += ((s64)0x1);
      }
    }
    (A_0032F)((A_000F8), ((s64)0x8));
    ((A_001B1)->A_00041) = ((A_00334)((A_000F8), (((A_001B1)->A_00040) * ((s64)0x8)), (A_001B5)));
    (A_00338)((A_000F9), (A_001B5));
  }
  if ((s64)0x0)
  {
    (A_00267)((A_001B1));
  }
  (A_00228)((A_001B1), (NULL));
  if ((s64)0x0)
  {
    (A_00267)((A_001B1));
  }
  (A_00214)((A_001B1), (NULL), (NULL));
  if ((s64)0x0)
  {
    (A_00267)((A_001B1));
  }
  return A_001B1;
}

u64 A_001BE/*type_equal*/(A_0000D (*A_001BC/*a*/), A_0000D (*A_001BD/*b*/))
{
  s64 A_001BF/*the_kind*/ = 0;

  (A_002EB)(((u8 *)"\x31\x38\x33\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_001BC) != (NULL)));
  (A_002EB)(((u8 *)"\x31\x38\x33\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x62\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_001BD) != (NULL)));
  if ((A_001BC) == (A_001BD))
  {
    return (s64)0x1;
  }
  if (((A_001BC)->A_0000E) != ((A_001BD)->A_0000E))
  {
    return (s64)0x0;
  }
  (A_001BF) = ((A_001BC)->A_0000E);
  if (((A_001C2)((A_001BF))) || ((A_001BF) == ((s64)0x9)))
  {
    return (s64)0x1;
  }
  if ((A_001BF) == ((s64)0xA))
  {
    return (A_001BE)(((A_001BC)->A_00013), ((A_001BD)->A_00013));
  }
  if ((A_001BF) == ((s64)0xC))
  {
    return ((A_001BC)->A_00012) == ((A_001BD)->A_00012);
  }
  if ((A_001BF) == ((s64)0xB))
  {
    if (!((A_001BE)(((A_001BC)->A_00013), ((A_001BD)->A_00013))))
    {
      return (s64)0x0;
    }
    if (((A_001BC)->A_00014) != ((A_001BD)->A_00014))
    {
      return (s64)0x0;
    }
    {
      s64 A_001C0/*i*/ = 0;
      for (; (A_001C0) < ((A_001BC)->A_00014); (A_001C0) += ((s64)0x1))
      {
        if (!((A_001BE)((((A_001BC)->A_00015)[A_001C0]), (((A_001BD)->A_00015)[A_001C0]))))
        {
          return (s64)0x0;
        }
      }
    }
    return (s64)0x1;
  }
  (A_002EB)(((u8 *)"\x31\x38\x36\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x30\x29\x3B"), (u32)((s64)0x0));
  return (s64)0x0;
}

u64 A_001C2/*type_kind_is_integer*/(s64 A_001C1/*type_kind*/)
{
  return ((((((((A_001C1) == ((s64)0x5)) || ((A_001C1) == ((s64)0x1))) || ((A_001C1) == ((s64)0x6))) || ((A_001C1) == ((s64)0x2))) || ((A_001C1) == ((s64)0x7))) || ((A_001C1) == ((s64)0x3))) || ((A_001C1) == ((s64)0x8))) || ((A_001C1) == ((s64)0x4));
}

u64 A_001C5/*type_implicit_cast_is_possible*/(A_0000D (*A_001C3/*dst*/), A_0000D (*A_001C4/*src*/))
{
  s64 A_001C6/*the_kind*/ = 0;

  (A_002EB)(((u8 *)"\x31\x38\x37\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x64\x73\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_001C3) != (NULL)));
  (A_002EB)(((u8 *)"\x31\x38\x37\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x72\x63\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_001C4) != (NULL)));
  if ((A_001C3) == (A_001C4))
  {
    return (s64)0x1;
  }
  if (((A_001C2)(((A_001C3)->A_0000E))) && ((A_001C2)(((A_001C4)->A_0000E))))
  {
    return (s64)0x1;
  }
  if (((A_001C3)->A_0000E) != ((A_001C4)->A_0000E))
  {
    return (s64)0x0;
  }
  (A_001C6) = ((A_001C3)->A_0000E);
  if ((A_001C6) == ((s64)0x9))
  {
    return (s64)0x1;
  }
  if ((A_001C6) == ((s64)0xC))
  {
    return (A_001C3) == (A_001C4);
  }
  if ((A_001C6) == ((s64)0xA))
  {
    if (((((A_001C4)->A_00013)->A_0000E) == ((s64)0x9)) || ((((A_001C3)->A_00013)->A_0000E) == ((s64)0x9)))
    {
      return (s64)0x1;
    }
    return (A_001BE)(((A_001C4)->A_00013), ((A_001C3)->A_00013));
  }
  if ((A_001C3)->A_0000F)
  {
    (A_00293)(((s64)0x0), ((A_001C3)->A_0000F), ((u8 *)"\x63\x61\x6E\x27\x74\x20\x63\x68\x65\x63\x6B\x20\x69\x66\x20\x74\x79\x70\x65\x5F\x69\x6D\x70\x6C\x69\x63\x69\x74\x5F\x63\x61\x73\x74\x5F\x69\x73\x5F\x70\x6F\x73\x73\x69\x62\x6C\x65"));
  }
  if ((A_001C4)->A_0000F)
  {
    (A_00293)(((s64)0x0), ((A_001C4)->A_0000F), ((u8 *)"\x63\x61\x6E\x27\x74\x20\x63\x68\x65\x63\x6B\x20\x69\x66\x20\x74\x79\x70\x65\x5F\x69\x6D\x70\x6C\x69\x63\x69\x74\x5F\x63\x61\x73\x74\x5F\x69\x73\x5F\x70\x6F\x73\x73\x69\x62\x6C\x65"));
  }
  (A_002EB)(((u8 *)"\x31\x38\x39\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x30\x29\x3B"), (u32)((s64)0x0));
  return (s64)0x0;
}

A_00031 A_001C8/*rvalue_from*/(A_00031 A_001C7/*value*/)
{
  ((A_001C7).A_00035) = ((s64)0x0);
  return A_001C7;
}

u64 A_001CA/*type_kind_can_be_boolified*/(s64 A_001C9/*type_kind*/)
{
  if ((A_001C9) == ((s64)0xC))
  {
    return (s64)0x0;
  }
  return (s64)0x1;
}

A_00031 A_001CD/*fe_compile_expression_recursively*/(A_00038 (*A_001CB/*expr*/), A_0002C (*A_001CC/*current_scope*/))
{
  A_00031 A_001CE/*result*/ = {0};
  s64 A_001CF/*expr_kind*/ = 0;

  (A_002EB)(((u8 *)"\x31\x39\x31\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x65\x78\x70\x72\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_001CB) != (NULL)));
  (A_002EB)(((u8 *)"\x31\x39\x31\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x63\x75\x72\x72\x65\x6E\x74\x5F\x73\x63\x6F\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_001CC) != (NULL)));
  (A_001CF) = ((A_001CB)->A_00039);
  if ((A_001CF) == ((s64)0xA))
  {
    A_00019 (*A_001D0/*symbol*/) = NULL;

    (A_001D0) = ((A_001CB)->A_00042);
    if ((A_001D0) == (NULL))
    {
      (A_001D0) = ((A_00239)((A_001CC), (((A_001CB)->A_0003A)->A_00009), (((A_001CB)->A_0003A)->A_00008)));
      if ((A_001D0) == (NULL))
      {
        (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x6E\x6F\x20\x73\x75\x63\x68\x20\x73\x79\x6D\x62\x6F\x6C"));
      }
      ((A_001CB)->A_00042) = (A_001D0);
    }
    if ((((A_001D0)->A_00020) == ((s64)0x3)) && (!((A_001D0)->A_00021)))
    {
      (A_00293)(((s64)0x3), ((A_001CB)->A_0003A), ((u8 *)"\x75\x73\x69\x6E\x67\x20\x61\x20\x6C\x6F\x63\x61\x6C\x20\x76\x61\x72\x69\x61\x62\x6C\x65\x20\x62\x65\x66\x6F\x72\x65\x20\x69\x74\x27\x73\x20\x64\x65\x63\x6C\x61\x72\x65\x64"));
      (A_00293)(((s64)0x1), ((A_001D0)->A_0001A), ((u8 *)"\x74\x68\x65\x20\x64\x65\x63\x6C\x61\x72\x61\x74\x69\x6F\x6E\x20\x69\x73\x20\x68\x65\x72\x65"));
      (A_00367)((u32)((s64)0x1));
    }
    if ((((A_001D0)->A_0001B) == (NULL)) && ((A_001CB)->A_0003A))
    {
      (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x73\x79\x6D\x62\x6F\x6C\x2E\x74\x79\x70\x65\x20\x3D\x3D\x20\x6E\x75\x6C\x6C"));
    }
    (A_002EB)(((u8 *)"\x31\x39\x34\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x74\x79\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_001D0)->A_0001B) != (NULL)));
    ((A_001CE).A_00033) = ((A_001D0)->A_0001B);
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
    ((A_001D0)->A_00022) += ((s64)0x1);
    if (((A_001D0)->A_00020) != ((s64)0x5))
    {
      ((A_001CE).A_00035) = ((((A_001D0)->A_0001B)->A_0000E) != ((s64)0xB));
    }
    else
    {
      ((A_001CE).A_00036) = ((s64)0x1);
      ((A_001CE).A_00034) = ((A_001D0)->A_00023);
    }
  }
  else if ((A_001CF) == ((s64)0x44))
  {
    A_00031 A_001D1/*function_value*/ = {0};
    A_0000D (*A_001D2/*function_type*/) = NULL;

    (A_001D1) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003B), (A_001CC)))));
    (A_001D2) = ((A_001D1).A_00033);
    if (((A_001D2)->A_0000E) == ((s64)0xA))
    {
      (A_001D2) = ((A_001D2)->A_00013);
    }
    if (((A_001D2)->A_0000E) != ((s64)0xB))
    {
      (A_00293)(((s64)0x0), ((A_001D1).A_00032), ((u8 *)"\x6E\x6F\x74\x20\x61\x20\x66\x75\x6E\x63\x74\x69\x6F\x6E"));
    }
    if (((A_001CB)->A_00040) < ((A_001D2)->A_00014))
    {
      (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x6E\x6F\x74\x20\x65\x6E\x6F\x75\x67\x68\x20\x61\x72\x67\x75\x6D\x65\x6E\x74\x73"));
    }
    if (((A_001CB)->A_00040) > ((A_001D2)->A_00014))
    {
      (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x74\x6F\x6F\x20\x6D\x61\x6E\x79\x20\x61\x72\x67\x75\x6D\x65\x6E\x74\x73"));
    }
    {
      s64 A_001D3/*i*/ = 0;
      for (; (A_001D3) < ((A_001CB)->A_00040); (A_001D3) += ((s64)0x1))
      {
        A_00038 (*A_001D4/*arg*/) = NULL;
        A_00031 A_001D5/*arg_value*/ = {0};
        A_0000D (*A_001D6/*param_type*/) = NULL;

        (A_001D4) = (((A_001CB)->A_00041)[A_001D3]);
        (A_001D5) = ((A_001C8)(((A_001CD)((A_001D4), (A_001CC)))));
        (A_001D6) = (((A_001D2)->A_00015)[A_001D3]);
        if (!((A_001C5)((A_001D6), ((A_001D5).A_00033))))
        {
          (A_00293)(((s64)0x0), ((A_001D5).A_00032), ((u8 *)"\x74\x68\x65\x20\x61\x72\x67\x75\x6D\x65\x6E\x74\x20\x74\x79\x70\x65\x20\x64\x6F\x65\x73\x6E\x27\x74\x20\x6D\x61\x74\x63\x68\x20\x74\x68\x65\x20\x70\x61\x72\x61\x6D\x65\x74\x65\x72\x20\x74\x79\x70\x65"));
        }
      }
    }
    ((A_001CE).A_00033) = ((A_001D2)->A_00013);
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if ((A_001CF) == ((s64)0xB))
  {
    ((A_001CE).A_00033) = (&(A_00101));
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if ((A_001CF) == ((s64)0x18))
  {
    ((A_001CE).A_00033) = (&(A_00102));
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if ((A_001CF) == ((s64)0x16))
  {
    u64 A_001D7/*value*/ = 0;
    u64 A_001D8/*base*/ = 0;
    s64 A_001D9/*size*/ = 0;
    u8 (*A_001DA/*text*/) = NULL;

    (A_001D8) = ((s64)0xA);
    (A_001D9) = (((A_001CB)->A_0003A)->A_00009);
    (A_001DA) = (((A_001CB)->A_0003A)->A_00008);
    if (((A_001D9) > ((s64)0x2)) && (((A_001DA)[(s64)0x0]) == ((s64)0x30)))
    {
      if (((A_001DA)[(s64)0x1]) == ((s64)0x78))
      {
        (A_001DA) += ((s64)0x2);
        (A_001D9) -= ((s64)0x2);
        (A_001D8) = ((s64)0x10);
      }
      else if (((A_001DA)[(s64)0x1]) == ((s64)0x62))
      {
        (A_001DA) += ((s64)0x2);
        (A_001D9) -= ((s64)0x2);
        (A_001D8) = ((s64)0x2);
      }
      else if (((A_001DA)[(s64)0x1]) == ((s64)0x6F))
      {
        (A_001DA) += ((s64)0x2);
        (A_001D9) -= ((s64)0x2);
        (A_001D8) = ((s64)0x8);
      }
      else if (((A_001DA)[(s64)0x1]) == ((s64)0x64))
      {
        (A_001DA) += ((s64)0x2);
        (A_001D9) -= ((s64)0x2);
        (A_001D8) = ((s64)0xA);
      }
    }
    {
      s64 A_001DB/*i*/ = 0;
      for (; (A_001DB) < (A_001D9); (A_001DB) += ((s64)0x1))
      {
        u64 A_001DC/*ascii_digit*/ = 0;

        (A_001DC) = ((A_001DA)[A_001DB]);
        if ((A_001DC) != ((s64)0x5F))
        {
          u64 A_001DD/*digit_int*/ = 0;

          (A_001DD) = ((A_002DE)((u32)(A_001DC)));
          if ((A_001DD) >= (A_001D8))
          {
            (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x62\x61\x64\x20\x69\x6E\x74\x65\x67\x65\x72\x20\x63\x6F\x6E\x73\x74\x61\x6E\x74"));
          }
          (A_001D7) *= (A_001D8);
          (A_001D7) += (A_001DD);
        }
      }
    }
    ((A_001CE).A_00033) = (&(A_000FD));
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
    ((A_001CE).A_00036) = ((s64)0x1);
    ((A_001CE).A_00034) = (A_001D7);
  }
  else if ((A_001CF) == ((s64)0x17))
  {
    ((A_001CE).A_00033) = (&(A_000FD));
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if ((A_001CF) == ((s64)0x1E))
  {
    ((A_001CE).A_00033) = (&(A_000FC));
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
    ((A_001CE).A_00036) = ((s64)0x1);
    ((A_001CE).A_00034) = ((A_00116)(((A_00201)(((A_001CB)->A_0003B), (A_001CC)))));
  }
  else if ((A_001CF) == ((s64)0x1F))
  {
    ((A_001CE).A_00033) = (&(A_000FC));
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
    ((A_001CE).A_00036) = ((s64)0x1);
    ((A_001CE).A_00034) = ((A_0010F)(((A_00201)(((A_001CB)->A_0003B), (A_001CC)))));
  }
  else if ((A_001CF) == ((s64)0x15))
  {
    ((A_001CE).A_00033) = (&(A_00102));
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if ((A_001CF) == ((s64)0x37))
  {
    A_00031 A_001DE/*lhsv*/ = {0};
    A_00031 A_001DF/*rhsv*/ = {0};

    (A_001DE) = ((A_001CD)(((A_001CB)->A_0003B), (A_001CC)));
    (A_001DF) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003C), (A_001CC)))));
    if (!((A_001DE).A_00035))
    {
      (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x6E\x65\x65\x64\x20\x61\x6E\x20\x6C\x76\x61\x6C\x75\x65\x20\x6F\x6E\x20\x74\x68\x65\x20\x6C\x65\x66\x74\x20\x6F\x66\x20\x74\x68\x65\x20\x61\x73\x73\x69\x67\x6E\x6D\x65\x6E\x74\x20\x6F\x70\x65\x72\x61\x74\x6F\x72"));
    }
    if (!((A_001C5)(((A_001DE).A_00033), ((A_001DF).A_00033))))
    {
      (A_00293)(((s64)0x0), ((A_001DF).A_00032), ((u8 *)"\x74\x68\x65\x20\x76\x61\x6C\x75\x65\x20\x63\x61\x6E\x27\x74\x20\x62\x65\x20\x69\x6D\x70\x6C\x69\x63\x69\x74\x6C\x79\x20\x63\x61\x73\x74\x20\x74\x6F\x20\x74\x68\x65\x20\x74\x79\x70\x65\x20\x6F\x6E\x20\x74\x68\x65\x20\x6C\x65\x66\x74\x20\x6F\x66\x20\x74\x68\x65\x20\x61\x73\x73\x69\x67\x6E\x6D\x65\x6E\x74"));
    }
    ((A_001CE).A_00033) = ((A_001DE).A_00033);
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if (((((((((((((((((A_001CF) == ((s64)0x25)) || ((A_001CF) == ((s64)0x26))) || ((A_001CF) == ((s64)0x27))) || ((A_001CF) == ((s64)0x2A))) || ((A_001CF) == ((s64)0x28))) || ((A_001CF) == ((s64)0x29))) || ((A_001CF) == ((s64)0x2B))) || ((A_001CF) == ((s64)0x2C))) || ((A_001CF) == ((s64)0x3A))) || ((A_001CF) == ((s64)0x3B))) || ((A_001CF) == ((s64)0x3C))) || ((A_001CF) == ((s64)0x3F))) || ((A_001CF) == ((s64)0x3D))) || ((A_001CF) == ((s64)0x3E))) || ((A_001CF) == ((s64)0x40))) || ((A_001CF) == ((s64)0x41)))
  {
    u64 A_001E0/*is_assign*/ = 0;
    A_00031 A_001E1/*lhsv*/ = {0};
    A_00031 A_001E2/*rhsv*/ = {0};

    (A_001E0) = (((((((((A_001CF) == ((s64)0x3A)) || ((A_001CF) == ((s64)0x3B))) || ((A_001CF) == ((s64)0x3C))) || ((A_001CF) == ((s64)0x3F))) || ((A_001CF) == ((s64)0x3D))) || ((A_001CF) == ((s64)0x3E))) || ((A_001CF) == ((s64)0x40))) || ((A_001CF) == ((s64)0x41)));
    (A_001E1) = ((A_001CD)(((A_001CB)->A_0003B), (A_001CC)));
    if (!(A_001E0))
    {
      (A_001E1) = ((A_001C8)((A_001E1)));
    }
    (A_001E2) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003C), (A_001CC)))));
    if ((A_001E0) && (!((A_001E1).A_00035)))
    {
      (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x6E\x65\x65\x64\x20\x61\x6E\x20\x6C\x76\x61\x6C\x75\x65\x20\x6F\x6E\x20\x74\x68\x65\x20\x6C\x65\x66\x74\x20\x6F\x66\x20\x74\x68\x65\x20\x61\x73\x73\x69\x67\x6E\x6D\x65\x6E\x74\x20\x6F\x70\x65\x72\x61\x74\x6F\x72"));
    }
    if ((!((A_001C2)((((A_001E1).A_00033)->A_0000E)))) || (!((A_001C2)((((A_001E2).A_00033)->A_0000E)))))
    {
      (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x69\x6E\x74\x65\x67\x65\x72\x73\x20\x6F\x6E\x6C\x79\x2C\x20\x70\x6C\x65\x61\x73\x65"));
    }
    if ((((A_001CF) == ((s64)0x2B)) || ((A_001CF) == ((s64)0x2C))) || (A_001E0))
    {
      ((A_001CE).A_00033) = ((A_001E1).A_00033);
      ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
    }
    else
    {
      s64 A_001E3/*lsize*/ = 0;
      s64 A_001E4/*rsize*/ = 0;

      (A_001E3) = ((A_00116)(((A_001E1).A_00033)));
      (A_001E4) = ((A_00116)(((A_001E2).A_00033)));
      if ((A_001E3) > (A_001E4))
      {
        ((A_001CE).A_00033) = ((A_001E1).A_00033);
      }
      else
      {
        ((A_001CE).A_00033) = ((A_001E2).A_00033);
      }
      ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
    }
  }
  else if (((((((A_001CF) == ((s64)0x2E)) || ((A_001CF) == ((s64)0x2F))) || ((A_001CF) == ((s64)0x30))) || ((A_001CF) == ((s64)0x31))) || ((A_001CF) == ((s64)0x32))) || ((A_001CF) == ((s64)0x33)))
  {
    A_00031 A_001E5/*lhsv*/ = {0};
    A_00031 A_001E6/*rhsv*/ = {0};

    (A_001E5) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003B), (A_001CC)))));
    (A_001E6) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003C), (A_001CC)))));
    if (!((A_001C5)(((A_001E5).A_00033), ((A_001E6).A_00033))))
    {
      (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x74\x68\x65\x20\x76\x61\x6C\x75\x65\x73\x20\x63\x61\x6E\x27\x74\x20\x62\x65\x20\x69\x6D\x70\x6C\x69\x63\x69\x74\x6C\x79\x20\x63\x61\x73\x74\x20\x66\x6F\x72\x20\x61\x20\x76\x61\x6C\x69\x64\x20\x63\x6F\x6D\x70\x61\x72\x61\x73\x69\x6F\x6E"));
    }
    ((A_001CE).A_00033) = (&(A_000FE));
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if (((A_001CF) == ((s64)0x36)) || ((A_001CF) == ((s64)0x35)))
  {
    A_00031 A_001E7/*lhsv*/ = {0};
    A_00031 A_001E8/*rhsv*/ = {0};

    (A_001E7) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003B), (A_001CC)))));
    (A_001E8) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003C), (A_001CC)))));
    if (!((A_001CA)((((A_001E7).A_00033)->A_0000E))))
    {
      (A_00293)(((s64)0x0), ((A_001E7).A_00032), ((u8 *)"\x69\x6D\x70\x6F\x73\x73\x69\x62\x6C\x65\x20\x74\x6F\x20\x62\x6F\x6F\x6C\x69\x66\x79"));
    }
    if (!((A_001CA)((((A_001E8).A_00033)->A_0000E))))
    {
      (A_00293)(((s64)0x0), ((A_001E8).A_00032), ((u8 *)"\x69\x6D\x70\x6F\x73\x73\x69\x62\x6C\x65\x20\x74\x6F\x20\x62\x6F\x6F\x6C\x69\x66\x79"));
    }
    ((A_001CE).A_00033) = (&(A_000FD));
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if ((A_001CF) == ((s64)0x1D))
  {
    A_00031 A_001E9/*subv*/ = {0};

    (A_001E9) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003B), (A_001CC)))));
    if (!((A_001CA)((((A_001E9).A_00033)->A_0000E))))
    {
      (A_00293)(((s64)0x0), ((A_001E9).A_00032), ((u8 *)"\x69\x6D\x70\x6F\x73\x73\x69\x62\x6C\x65\x20\x74\x6F\x20\x62\x6F\x6F\x6C\x69\x66\x79"));
    }
    ((A_001CE).A_00033) = (&(A_000FD));
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if ((((A_001CF) == ((s64)0x19)) || ((A_001CF) == ((s64)0x1A))) || ((A_001CF) == ((s64)0x1B)))
  {
    A_00031 A_001EA/*subv*/ = {0};

    (A_001EA) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003B), (A_001CC)))));
    if (!((A_001C2)((((A_001EA).A_00033)->A_0000E))))
    {
      (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x69\x6E\x74\x65\x67\x65\x72\x73\x20\x6F\x6E\x6C\x79\x2C\x20\x70\x6C\x65\x61\x73\x65"));
    }
    ((A_001CE).A_00033) = ((A_001EA).A_00033);
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if ((A_001CF) == ((s64)0x20))
  {
    A_00031 A_001EB/*subv*/ = {0};

    (A_001EB) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003B), (A_001CC)))));
    if ((((A_001EB).A_00033)->A_0000E) != ((s64)0xA))
    {
      (A_00293)(((s64)0x0), ((A_001EB).A_00032), ((u8 *)"\x6E\x65\x65\x64\x20\x61\x20\x70\x6F\x69\x6E\x74\x65\x72\x20\x74\x6F\x20\x67\x65\x74\x20\x74\x68\x65\x20\x76\x61\x6C\x75\x65\x20\x62\x79\x20\x70\x6F\x69\x6E\x74\x65\x72"));
    }
    ((A_001CE).A_00033) = (((A_001EB).A_00033)->A_00013);
    ((A_001CE).A_00035) = ((s64)0x1);
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if ((A_001CF) == ((s64)0x21))
  {
    A_00031 A_001EC/*subv*/ = {0};
    A_0000D (*A_001ED/*ptr_to_lvalue_type*/) = NULL;

    (A_001EC) = ((A_001CD)(((A_001CB)->A_0003B), (A_001CC)));
    if (!((A_001EC).A_00035))
    {
      (A_00293)(((s64)0x0), ((A_001EC).A_00032), ((u8 *)"\x6E\x65\x65\x64\x20\x61\x6E\x20\x6C\x76\x61\x6C\x75\x65\x20\x74\x6F\x20\x74\x61\x6B\x65\x20\x74\x68\x65\x20\x70\x6F\x69\x6E\x74\x65\x72"));
    }
    (A_0032F)((A_000F8), ((s64)0x8));
    (A_001ED) = ((A_0032B)((A_000F8), ((s64)0x50)));
    ((A_001ED)->A_0000E) = ((s64)0xA);
    ((A_001ED)->A_0000F) = ((A_001CB)->A_0003A);
    ((A_001ED)->A_00013) = ((A_001EC).A_00033);
    ((A_001CE).A_00033) = (A_001ED);
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if ((A_001CF) == ((s64)0x34))
  {
    A_00031 A_001EE/*lhsv*/ = {0};
    A_00031 A_001EF/*rhsv*/ = {0};

    (A_001EE) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003B), (A_001CC)))));
    (A_001EF) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003C), (A_001CC)))));
    if ((((A_001EE).A_00033)->A_0000E) != ((s64)0xA))
    {
      (A_00293)(((s64)0x0), ((A_001EE).A_00032), ((u8 *)"\x6E\x65\x65\x64\x20\x61\x20\x70\x6F\x69\x6E\x74\x65\x72\x20\x74\x6F\x20\x67\x65\x74\x20\x74\x68\x65\x20\x76\x61\x6C\x75\x65\x20\x61\x74\x20\x74\x68\x65\x20\x69\x6E\x64\x65\x78"));
    }
    if (!((A_001C2)((((A_001EF).A_00033)->A_0000E))))
    {
      (A_00293)(((s64)0x0), ((A_001EF).A_00032), ((u8 *)"\x74\x68\x65\x20\x69\x6E\x64\x65\x78\x20\x6D\x75\x73\x74\x20\x62\x65\x20\x6F\x66\x20\x61\x6E\x20\x69\x6E\x74\x65\x67\x65\x72\x20\x74\x79\x70\x65"));
    }
    ((A_001CE).A_00033) = (((A_001EE).A_00033)->A_00013);
    ((A_001CE).A_00035) = ((s64)0x1);
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if ((A_001CF) == ((s64)0x42))
  {
    A_00031 A_001F0/*subv*/ = {0};
    A_0000D (*A_001F1/*type*/) = NULL;

    (A_001F0) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003B), (A_001CC)))));
    (A_001F1) = ((A_00201)(((A_001CB)->A_0003C), (A_001CC)));
    if (!((A_0011F)((A_001F1), ((A_001F0).A_00033))))
    {
      (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x69\x6D\x70\x6F\x73\x73\x69\x62\x6C\x65\x20\x63\x61\x73\x74\x2C\x20\x73\x6F\x72\x72\x79"));
    }
    ((A_001CE).A_00033) = (A_001F1);
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if ((A_001CF) == ((s64)0x2D))
  {
    A_00031 A_001F2/*lvalue_struct_or_rvalue_ptr_to_struct*/ = {0};
    A_0000D (*A_001F3/*struct_type*/) = NULL;
    A_00007 (*A_001F4/*name*/) = NULL;
    A_0000D (*A_001F5/*member_type*/) = NULL;

    (A_001F2) = ((A_001CD)(((A_001CB)->A_0003B), (A_001CC)));
    if ((((A_001F2).A_00033)->A_0000E) == ((s64)0xC))
    {
      (A_001F3) = ((A_001F2).A_00033);
      if (!((A_001F2).A_00035))
      {
        (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x74\x68\x65\x20\x73\x74\x72\x75\x63\x74\x20\x69\x73\x20\x4E\x4F\x54\x20\x61\x6E\x20\x6C\x76\x61\x6C\x75\x65"));
      }
    }
    else if ((((A_001F2).A_00033)->A_0000E) == ((s64)0xA))
    {
      (A_001F3) = (((A_001F2).A_00033)->A_00013);
      if (((A_001F3)->A_0000E) != ((s64)0xC))
      {
        (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x6E\x6F\x74\x20\x61\x20\x70\x6F\x69\x6E\x74\x65\x72\x20\x74\x6F\x20\x73\x74\x72\x75\x63\x74"));
      }
    }
    else
    {
      (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x6E\x6F\x74\x20\x61\x20\x73\x74\x72\x75\x63\x74\x20\x61\x6E\x64\x20\x6E\x6F\x74\x20\x61\x20\x70\x6F\x69\x6E\x74\x65\x72\x20\x74\x6F\x20\x73\x74\x72\x75\x63\x74"));
    }
    (A_002EB)(((u8 *)"\x32\x32\x33\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x72\x75\x63\x74\x5F\x74\x79\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_001F3) != (NULL)));
    (A_002EB)(((u8 *)"\x32\x32\x33\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x72\x75\x63\x74\x5F\x74\x79\x70\x65\x2E\x74\x79\x70\x65\x5F\x6B\x69\x6E\x64\x20\x3D\x3D\x20\x54\x59\x50\x45\x5F\x53\x54\x52\x55\x43\x54\x29\x3B"), (((A_001F3)->A_0000E) == ((s64)0xC)));
    if ((((A_001CB)->A_0003C)->A_00039) != ((s64)0xA))
    {
      (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x65\x78\x70\x65\x63\x74\x65\x64\x20\x74\x68\x65\x20\x6E\x61\x6D\x65\x20\x6F\x66\x20\x61\x20\x6D\x65\x6D\x62\x65\x72\x20\x6F\x66\x20\x74\x68\x65\x20\x73\x74\x72\x75\x63\x74"));
    }
    (A_001F4) = (((A_001CB)->A_0003C)->A_0003A);
    {
      s64 A_001F6/*i*/ = 0;
      for (; (A_001F6) < ((A_001F3)->A_00016); (A_001F6) += ((s64)0x1))
      {
        A_0000D (*A_001F7/*ith_member_type*/) = NULL;
        A_00007 (*A_001F8/*member_name*/) = NULL;

        (A_001F7) = (((A_001F3)->A_00017)[A_001F6]);
        (A_002EB)(((u8 *)"\x32\x32\x34\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x69\x74\x68\x5F\x6D\x65\x6D\x62\x65\x72\x5F\x74\x79\x70\x65\x2E\x6E\x61\x6D\x65\x5F\x74\x6F\x6B\x65\x6E\x5F\x6F\x70\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_001F7)->A_00010) != (NULL)));
        (A_001F8) = ((A_001F7)->A_00010);
        if ((((A_001F8)->A_00009) == ((A_001F4)->A_00009)) && ((A_002D1)(((A_001F8)->A_00008), ((A_001F4)->A_00008), ((A_001F4)->A_00009))))
        {
          (A_001F5) = (A_001F7);
          break;
        }
      }
    }
    if ((A_001F5) == (NULL))
    {
      (A_00293)(((s64)0x0), (((A_001CB)->A_0003C)->A_0003A), ((u8 *)"\x6E\x6F\x74\x20\x61\x20\x6D\x65\x6D\x62\x65\x72\x20\x6F\x66\x20\x74\x68\x65\x20\x73\x74\x72\x75\x63\x74"));
    }
    ((A_001CE).A_00033) = (A_001F5);
    ((A_001CE).A_00035) = ((s64)0x1);
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if (((A_001CF) == ((s64)0x38)) || ((A_001CF) == ((s64)0x39)))
  {
    A_00031 A_001F9/*lhsv*/ = {0};
    A_00031 A_001FA/*rhsv*/ = {0};

    (A_001F9) = ((A_001CD)(((A_001CB)->A_0003B), (A_001CC)));
    (A_001FA) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003C), (A_001CC)))));
    if (!((A_001F9).A_00035))
    {
      (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x6E\x65\x65\x64\x20\x61\x6E\x20\x6C\x76\x61\x6C\x75\x65\x20\x6F\x6E\x20\x74\x68\x65\x20\x6C\x65\x66\x74\x20\x6F\x66\x20\x74\x68\x65\x20\x61\x73\x73\x69\x67\x6E\x6D\x65\x6E\x74\x20\x6F\x70\x65\x72\x61\x74\x6F\x72"));
    }
    if (((A_001C2)((((A_001F9).A_00033)->A_0000E))) && ((A_001C2)((((A_001FA).A_00033)->A_0000E))))
    {
    }
    else if (((((A_001F9).A_00033)->A_0000E) == ((s64)0xA)) && ((A_001C2)((((A_001FA).A_00033)->A_0000E))))
    {
      if ((((((A_001F9).A_00033)->A_00013)->A_0000E) == ((s64)0x9)) || (((((A_001F9).A_00033)->A_00013)->A_0000E) == ((s64)0xB)))
      {
        (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x74\x68\x65\x20\x70\x6F\x69\x6E\x74\x65\x72\x20\x69\x73\x20\x75\x6E\x69\x74\x65\x72\x61\x74\x69\x76\x65"));
      }
    }
    else
    {
      (A_00293)(((s64)0x0), ((A_001FA).A_00032), ((u8 *)"\x74\x68\x65\x20\x76\x61\x6C\x75\x65\x20\x63\x61\x6E\x27\x74\x20\x62\x65\x20\x69\x6D\x70\x6C\x69\x63\x69\x74\x6C\x79\x20\x63\x61\x73\x74\x20\x74\x6F\x20\x74\x68\x65\x20\x74\x79\x70\x65\x20\x6F\x6E\x20\x74\x68\x65\x20\x6C\x65\x66\x74\x20\x6F\x66\x20\x74\x68\x65\x20\x61\x73\x73\x69\x67\x6E\x6D\x65\x6E\x74\x20\x6F\x70\x65\x72\x61\x74\x6F\x72"));
    }
    ((A_001CE).A_00033) = ((A_001F9).A_00033);
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
  }
  else if (((A_001CF) == ((s64)0x23)) || ((A_001CF) == ((s64)0x24)))
  {
    A_00031 A_001FB/*lhsv*/ = {0};
    A_00031 A_001FC/*rhsv*/ = {0};

    (A_001FB) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003B), (A_001CC)))));
    (A_001FC) = ((A_001C8)(((A_001CD)(((A_001CB)->A_0003C), (A_001CC)))));
    ((A_001CE).A_00032) = ((A_001CB)->A_0003A);
    if (((A_001C2)((((A_001FB).A_00033)->A_0000E))) && ((A_001C2)((((A_001FC).A_00033)->A_0000E))))
    {
      s64 A_001FD/*lsize*/ = 0;
      s64 A_001FE/*rsize*/ = 0;

      (A_001FD) = ((A_00116)(((A_001FB).A_00033)));
      (A_001FE) = ((A_00116)(((A_001FC).A_00033)));
      if ((A_001FD) > (A_001FE))
      {
        ((A_001CE).A_00033) = ((A_001FB).A_00033);
      }
      else
      {
        ((A_001CE).A_00033) = ((A_001FC).A_00033);
      }
    }
    else if (((((A_001FB).A_00033)->A_0000E) == ((s64)0xA)) && ((A_001C2)((((A_001FC).A_00033)->A_0000E))))
    {
      if ((((((A_001FB).A_00033)->A_00013)->A_0000E) == ((s64)0x9)) || (((((A_001FB).A_00033)->A_00013)->A_0000E) == ((s64)0xB)))
      {
        (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x74\x68\x65\x20\x70\x6F\x69\x6E\x74\x65\x72\x20\x69\x73\x20\x75\x6E\x69\x74\x65\x72\x61\x74\x69\x76\x65"));
      }
      ((A_001CE).A_00033) = ((A_001FB).A_00033);
    }
    else if ((((((A_001FC).A_00033)->A_0000E) == ((s64)0xA)) && ((A_001C2)((((A_001FB).A_00033)->A_0000E)))) && ((A_001CF) == ((s64)0x23)))
    {
      if ((((((A_001FC).A_00033)->A_00013)->A_0000E) == ((s64)0x9)) || (((((A_001FC).A_00033)->A_00013)->A_0000E) == ((s64)0xB)))
      {
        (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x74\x68\x65\x20\x70\x6F\x69\x6E\x74\x65\x72\x20\x69\x73\x20\x75\x6E\x69\x74\x65\x72\x61\x74\x69\x76\x65"));
      }
      ((A_001CE).A_00033) = ((A_001FC).A_00033);
    }
    else if ((((((A_001FB).A_00033)->A_0000E) == ((s64)0xA)) && ((((A_001FC).A_00033)->A_0000E) == ((s64)0xA))) && ((A_001CF) == ((s64)0x24)))
    {
      if (!((A_001BE)((((A_001FB).A_00033)->A_00013), (((A_001FC).A_00033)->A_00013))))
      {
        (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x73\x75\x62\x74\x72\x61\x63\x74\x69\x6E\x67\x20\x70\x6F\x69\x6E\x74\x65\x72\x73\x20\x6F\x66\x20\x64\x69\x66\x66\x65\x72\x65\x6E\x74\x20\x74\x79\x70\x65\x73"));
      }
      ((A_001CE).A_00033) = (&(A_000FC));
    }
    else
    {
      (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x61\x6E\x20\x69\x6D\x70\x6F\x73\x73\x69\x62\x6C\x65\x20\x61\x72\x69\x74\x68\x6D\x65\x74\x69\x63\x20\x6F\x70\x65\x72\x61\x74\x69\x6F\x6E"));
    }
  }
  else
  {
    (A_00293)(((s64)0x0), ((A_001CB)->A_0003A), ((u8 *)"\x69\x64\x75\x6E\x6F\x20\x68\x6F\x77\x20\x74\x6F\x20\x50\x52\x45\x2D\x63\x6F\x6D\x70\x69\x6C\x65\x20\x74\x68\x69\x73"));
  }
  (A_002EB)(((u8 *)"\x32\x33\x33\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x2E\x74\x79\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_001CE).A_00033) != (NULL)));
  (A_002EB)(((u8 *)"\x32\x33\x33\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x2E\x74\x6F\x6B\x65\x6E\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_001CE).A_00032) != (NULL)));
  ((A_001CB)->A_001C7) = (A_001CE);
  return A_001CE;
}

A_0000D (*A_00201/*type_from_ast*/(A_00038 (*A_001FF/*node*/), A_0002C (*A_00200/*current_scope*/)))
{
  A_0000D (*A_00202/*type*/) = NULL;
  s64 A_00203/*node_kind*/ = 0;
  s64 A_00204/*simple_type_kind*/ = 0;

  (A_002EB)(((u8 *)"\x32\x34\x31\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6E\x6F\x64\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_001FF) != (NULL)));
  (A_00203) = ((A_001FF)->A_00039);
  if ((A_00203) == ((s64)0xD))
  {
    (A_00204) = ((s64)0x5);
  }
  else if ((A_00203) == ((s64)0xE))
  {
    (A_00204) = ((s64)0x6);
  }
  else if ((A_00203) == ((s64)0xF))
  {
    (A_00204) = ((s64)0x7);
  }
  else if ((A_00203) == ((s64)0x10))
  {
    (A_00204) = ((s64)0x8);
  }
  else if ((A_00203) == ((s64)0x11))
  {
    (A_00204) = ((s64)0x1);
  }
  else if ((A_00203) == ((s64)0x12))
  {
    (A_00204) = ((s64)0x2);
  }
  else if ((A_00203) == ((s64)0x13))
  {
    (A_00204) = ((s64)0x3);
  }
  else if ((A_00203) == ((s64)0x14))
  {
    (A_00204) = ((s64)0x4);
  }
  else if ((A_00203) == ((s64)0xC))
  {
    (A_00204) = ((s64)0x9);
  }
  if (A_00204)
  {
    (A_0032F)((A_000F8), ((s64)0x8));
    (A_00202) = ((A_0032B)((A_000F8), ((s64)0x50)));
    ((A_00202)->A_0000E) = (A_00204);
    ((A_00202)->A_0000F) = ((A_001FF)->A_0003A);
  }
  else if ((A_00203) == ((s64)0x1C))
  {
    (A_0032F)((A_000F8), ((s64)0x8));
    (A_00202) = ((A_0032B)((A_000F8), ((s64)0x50)));
    ((A_00202)->A_0000E) = ((s64)0xA);
    ((A_00202)->A_0000F) = ((A_001FF)->A_0003A);
    ((A_00202)->A_00013) = ((A_00201)(((A_001FF)->A_0003B), (A_00200)));
  }
  else if ((A_00203) == ((s64)0x43))
  {
    void (*A_00205/*param_types*/) = NULL;

    (A_0032F)((A_000F8), ((s64)0x8));
    (A_00202) = ((A_0032B)((A_000F8), ((s64)0x50)));
    ((A_00202)->A_0000E) = ((s64)0xB);
    ((A_00202)->A_0000F) = ((A_001FF)->A_0003A);
    ((A_00202)->A_00013) = ((A_00201)(((A_001FF)->A_0003B), (A_00200)));
    (A_00205) = ((A_00321)((A_000F9)));
    {
      s64 A_00206/*i*/ = 0;
      for (; (A_00206) < ((A_001FF)->A_00040); (A_00206) += ((s64)0x1))
      {
        A_00038 (*A_00207/*param_node*/) = NULL;
        A_0000D (*A_00208/*param_type*/) = NULL;

        (A_00207) = (((A_001FF)->A_00041)[A_00206]);
        if (((A_00207)->A_00039) != ((s64)0x22))
        {
          (A_00293)(((s64)0x0), ((A_00207)->A_0003A), ((u8 *)"\x6E\x6F\x74\x20\x61\x20\x64\x65\x63\x6C\x61\x72\x61\x74\x69\x6F\x6E"));
        }
        (A_00208) = ((A_00201)(((A_00207)->A_0003C), (A_00200)));
        ((A_00208)->A_00010) = (((A_00207)->A_0003B)->A_0003A);
        ((A_00208)->A_00011) = ((((A_00207)->A_0003B)->A_00042)->A_0001D);
        (A_00334)((A_000F9), ((s64)0x8), (&(A_00208)));
        ((A_00202)->A_00014) += ((s64)0x1);
      }
    }
    (A_0032F)((A_000F8), ((s64)0x8));
    ((A_00202)->A_00015) = ((A_00334)((A_000F8), (((A_00202)->A_00014) * ((s64)0x8)), (A_00205)));
    (A_00338)((A_000F9), (A_00205));
  }
  else if ((A_00203) == ((s64)0x45))
  {
    void (*A_00209/*members_types*/) = NULL;

    (A_0032F)((A_000F8), ((s64)0x8));
    (A_00202) = ((A_0032B)((A_000F8), ((s64)0x50)));
    ((A_00202)->A_0000E) = ((s64)0xC);
    ((A_00202)->A_0000F) = ((A_001FF)->A_0003A);
    (A_002EB)(((u8 *)"\x32\x34\x37\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6E\x6F\x64\x65\x2E\x73\x74\x72\x75\x63\x74\x5F\x63\x5F\x6E\x61\x6D\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_001FF)->A_00045) != (NULL)));
    ((A_00202)->A_00012) = ((A_001FF)->A_00045);
    (A_00209) = ((A_00321)((A_000F9)));
    {
      s64 A_0020A/*i*/ = 0;
      for (; (A_0020A) < ((A_001FF)->A_00040); (A_0020A) += ((s64)0x1))
      {
        A_00038 (*A_0020B/*member_node*/) = NULL;
        A_0000D (*A_0020C/*param_type*/) = NULL;

        (A_0020B) = (((A_001FF)->A_00041)[A_0020A]);
        if (((A_0020B)->A_00039) != ((s64)0x22))
        {
          (A_00293)(((s64)0x0), ((A_0020B)->A_0003A), ((u8 *)"\x6E\x6F\x74\x20\x61\x20\x64\x65\x63\x6C\x61\x72\x61\x74\x69\x6F\x6E"));
        }
        (A_0020C) = ((A_00201)(((A_0020B)->A_0003C), (A_00200)));
        ((A_0020C)->A_00010) = (((A_0020B)->A_0003B)->A_0003A);
        ((A_0020C)->A_00011) = ((((A_0020B)->A_0003B)->A_00042)->A_0001D);
        (A_00334)((A_000F9), ((s64)0x8), (&(A_0020C)));
        ((A_00202)->A_00016) += ((s64)0x1);
      }
    }
    (A_0032F)((A_000F8), ((s64)0x8));
    ((A_00202)->A_00017) = ((A_00334)((A_000F8), (((A_00202)->A_00016) * ((s64)0x8)), (A_00209)));
    (A_00338)((A_000F9), (A_00209));
  }
  else if ((A_00203) == ((s64)0xA))
  {
    A_00019 (*A_0020D/*symbol*/) = NULL;

    (A_0020D) = ((A_001FF)->A_00042);
    if ((A_0020D) == (NULL))
    {
      (A_0020D) = ((A_00239)((A_00200), (((A_001FF)->A_0003A)->A_00009), (((A_001FF)->A_0003A)->A_00008)));
      if ((A_0020D) == (NULL))
      {
        (A_00293)(((s64)0x0), ((A_001FF)->A_0003A), ((u8 *)"\x6E\x6F\x20\x73\x75\x63\x68\x20\x73\x79\x6D\x62\x6F\x6C"));
      }
      ((A_001FF)->A_00042) = (A_0020D);
    }
    if (((A_0020D)->A_00020) != ((s64)0x4))
    {
      (A_00293)(((s64)0x0), ((A_001FF)->A_0003A), ((u8 *)"\x61\x20\x76\x61\x6C\x69\x64\x20\x73\x79\x6D\x62\x6F\x6C\x20\x62\x75\x74\x20\x6E\x6F\x74\x20\x61\x20\x74\x79\x70\x65"));
    }
    if (((A_0020D)->A_0001B) == (NULL))
    {
      A_00038 (*A_0020E/*decl_node*/) = NULL;
      A_0000D (*A_0020F/*actual_type*/) = NULL;
      A_0000D (*A_00210/*copy_type*/) = NULL;

      (A_002EB)(((u8 *)"\x32\x35\x32\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x61\x73\x74\x5F\x6E\x6F\x64\x65\x5F\x61\x73\x5F\x76\x6F\x69\x64\x5F\x70\x74\x72\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_0020D)->A_0001C) != (NULL)));
      (A_0020E) = ((A_0020D)->A_0001C);
      (A_002EB)(((u8 *)"\x32\x35\x32\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x64\x65\x63\x6C\x5F\x6E\x6F\x64\x65\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x3D\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), (((A_0020E)->A_00039) == ((s64)0x22)));
      (A_0032F)((A_000F8), ((s64)0x8));
      (A_0020F) = ((A_0032B)((A_000F8), ((s64)0x50)));
      ((A_0020D)->A_0001B) = (A_0020F);
      (A_00210) = ((A_00201)(((A_0020E)->A_0003C), (A_00200)));
      (*(A_0020F)) = (*(A_00210));
    }
    (A_00202) = ((A_0020D)->A_0001B);
  }
  else
  {
    (A_00293)(((s64)0x0), ((A_001FF)->A_0003A), ((u8 *)"\x6E\x6F\x74\x20\x61\x20\x74\x79\x70\x65"));
  }
  (A_002EB)(((u8 *)"\x32\x35\x34\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x74\x79\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00202) != (NULL)));
  return A_00202;
}

void A_00214/*fe_compile_statement_recursively*/(A_00038 (*A_00211/*stmt*/), A_0002C (*A_00212/*current_scope*/), A_00019 (*A_00213/*current_function_symbol*/))
{
  s64 A_00215/*stmt_kind*/ = 0;

  (A_00215) = ((A_00211)->A_00039);
  if ((A_00215) == ((s64)0x1))
  {
    {
      s64 A_00216/*i*/ = 0;
      for (; (A_00216) < ((A_00211)->A_00040); (A_00216) += ((s64)0x1))
      {
        A_00038 (*A_00217/*sub_stmt*/) = NULL;

        (A_00217) = (((A_00211)->A_00041)[A_00216]);
        if (((A_00217)->A_00039) == ((s64)0x22))
        {
          A_00019 (*A_00218/*symbol*/) = NULL;

          (A_00218) = (((A_00217)->A_0003B)->A_00042);
          (A_002EB)(((u8 *)"\x32\x35\x36\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x73\x74\x6F\x72\x61\x67\x65\x20\x3D\x3D\x20\x53\x54\x4F\x52\x41\x47\x45\x5F\x55\x4E\x44\x45\x46\x49\x4E\x45\x44\x29\x3B"), (((A_00218)->A_00020) == ((s64)0x0)));
          if ((A_00218)->A_0001F)
          {
            ((A_00218)->A_00020) = ((s64)0x4);
          }
          else if ((A_00218)->A_0001E)
          {
            ((A_00218)->A_00020) = ((s64)0x2);
          }
          else
          {
            ((A_00218)->A_00020) = ((s64)0x1);
          }
          if (((A_00218)->A_0001B) == (NULL))
          {
            ((A_00218)->A_0001B) = ((A_00201)(((A_00217)->A_0003C), (&((A_00211)->A_00044))));
          }
        }
      }
    }
    {
      s64 A_00219/*i*/ = 0;
      for (; (A_00219) < ((A_00211)->A_00040); (A_00219) += ((s64)0x1))
      {
        (A_00214)((((A_00211)->A_00041)[A_00219]), (&((A_00211)->A_00044)), (NULL));
      }
    }
  }
  else if ((A_00215) == ((s64)0x2))
  {
    {
      s64 A_0021A/*i*/ = 0;
      for (; (A_0021A) < ((A_00211)->A_00040); (A_0021A) += ((s64)0x1))
      {
        A_00038 (*A_0021B/*sub_stmt*/) = NULL;

        (A_0021B) = (((A_00211)->A_00041)[A_0021A]);
        if (((A_0021B)->A_00039) == ((s64)0x22))
        {
          A_00019 (*A_0021C/*symbol*/) = NULL;

          (A_0021C) = (((A_0021B)->A_0003B)->A_00042);
          (A_002EB)(((u8 *)"\x32\x35\x38\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x73\x74\x6F\x72\x61\x67\x65\x20\x3D\x3D\x20\x53\x54\x4F\x52\x41\x47\x45\x5F\x55\x4E\x44\x45\x46\x49\x4E\x45\x44\x29\x3B"), (((A_0021C)->A_00020) == ((s64)0x0)));
          if ((A_0021C)->A_0001F)
          {
            ((A_0021C)->A_00020) = ((s64)0x4);
          }
          else if ((A_0021C)->A_0001E)
          {
            ((A_0021C)->A_00020) = ((s64)0x2);
          }
          else if ((((A_0021B)->A_0003C)->A_00039) == ((s64)0x43))
          {
            ((A_0021C)->A_00020) = ((s64)0x1);
          }
          else
          {
            ((A_0021C)->A_00020) = ((s64)0x3);
          }
          if (((A_0021C)->A_0001B) == (NULL))
          {
            ((A_0021C)->A_0001B) = ((A_00201)(((A_0021B)->A_0003C), (&((A_00211)->A_00044))));
          }
        }
      }
    }
    {
      s64 A_0021D/*i*/ = 0;
      for (; (A_0021D) < ((A_00211)->A_00040); (A_0021D) += ((s64)0x1))
      {
        (A_00214)((((A_00211)->A_00041)[A_0021D]), (&((A_00211)->A_00044)), (A_00213));
      }
    }
  }
  else if ((((A_00215) == ((s64)0x22)) && ((((A_00211)->A_0003C)->A_00039) == ((s64)0x43))) && (((A_00211)->A_0003E) != (NULL)))
  {
    A_00019 (*A_0021E/*function_symbol*/) = NULL;

    (A_0021E) = (((A_00211)->A_0003B)->A_00042);
    (A_002EB)(((u8 *)"\x32\x36\x30\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x66\x75\x6E\x63\x74\x69\x6F\x6E\x5F\x73\x79\x6D\x62\x6F\x6C\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0021E) != (NULL)));
    {
      s64 A_0021F/*i*/ = 0;
      for (; (A_0021F) < (((A_00211)->A_0003C)->A_00040); (A_0021F) += ((s64)0x1))
      {
        A_00038 (*A_00220/*param_node*/) = NULL;
        A_00019 (*A_00221/*param_symbol*/) = NULL;

        (A_00220) = ((((A_00211)->A_0003C)->A_00041)[A_0021F]);
        (A_002EB)(((u8 *)"\x32\x36\x30\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x70\x61\x72\x61\x6D\x5F\x6E\x6F\x64\x65\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x3D\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), (((A_00220)->A_00039) == ((s64)0x22)));
        (A_00221) = (((A_00220)->A_0003B)->A_00042);
        (A_002EB)(((u8 *)"\x32\x36\x31\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x70\x61\x72\x61\x6D\x5F\x73\x79\x6D\x62\x6F\x6C\x2E\x73\x74\x6F\x72\x61\x67\x65\x20\x3D\x3D\x20\x53\x54\x4F\x52\x41\x47\x45\x5F\x55\x4E\x44\x45\x46\x49\x4E\x45\x44\x29\x3B"), (((A_00221)->A_00020) == ((s64)0x0)));
        ((A_00221)->A_00020) = ((s64)0x3);
        ((A_00221)->A_00021) = ((s64)0x1);
        if (((A_00221)->A_0001B) == (NULL))
        {
          ((A_00221)->A_0001B) = ((A_00201)(((A_00220)->A_0003C), (A_00212)));
        }
      }
    }
    (A_00214)(((A_00211)->A_0003E), (A_00212), (A_0021E));
  }
  else if ((A_00215) == ((s64)0x22))
  {
    A_00019 (*A_00222/*symbol*/) = NULL;

    (A_00222) = (((A_00211)->A_0003B)->A_00042);
    if (((A_00222)->A_00020) == ((s64)0x3))
    {
      ((A_00222)->A_00021) = ((s64)0x1);
    }
  }
  else if ((A_00215) == ((s64)0x46))
  {
  }
  else if ((A_00215) == ((s64)0x4))
  {
  }
  else if ((A_00215) == ((s64)0x5))
  {
  }
  else if ((A_00215) == ((s64)0x8))
  {
    (A_001CD)(((A_00211)->A_0003B), (A_00212));
    (A_00214)(((A_00211)->A_0003E), (A_00212), (A_00213));
    if ((A_00211)->A_0003F)
    {
      (A_00214)(((A_00211)->A_0003F), (A_00212), (A_00213));
    }
  }
  else if ((A_00215) == ((s64)0x6))
  {
    (A_001CD)(((A_00211)->A_0003B), (A_00212));
    (A_00214)(((A_00211)->A_0003E), (A_00212), (A_00213));
  }
  else if ((A_00215) == ((s64)0x7))
  {
    (A_00214)(((A_00211)->A_0003E), (A_00212), (A_00213));
    (A_001CD)(((A_00211)->A_0003B), (A_00212));
  }
  else if ((A_00215) == ((s64)0x9))
  {
    if ((A_00211)->A_0003B)
    {
      A_00038 (*A_00223/*decl*/) = NULL;
      A_00019 (*A_00224/*symbol*/) = NULL;

      (A_00223) = ((A_00211)->A_0003B);
      (A_002EB)(((u8 *)"\x32\x36\x35\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x64\x65\x63\x6C\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x3D\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), (((A_00223)->A_00039) == ((s64)0x22)));
      (A_00224) = (((A_00223)->A_0003B)->A_00042);
      (A_002EB)(((u8 *)"\x32\x36\x36\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x73\x74\x6F\x72\x61\x67\x65\x20\x3D\x3D\x20\x53\x54\x4F\x52\x41\x47\x45\x5F\x55\x4E\x44\x45\x46\x49\x4E\x45\x44\x29\x3B"), (((A_00224)->A_00020) == ((s64)0x0)));
      (A_002F1)(((u8 *)"\x32\x36\x36\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x63\x5F\x74\x79\x70\x65\x64\x65\x66\x5F\x74\x6F\x6B\x65\x6E\x20\x3D\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00224)->A_0001F) == (NULL)));
      (A_002F1)(((u8 *)"\x32\x36\x36\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x2E\x63\x5F\x65\x78\x74\x65\x72\x6E\x5F\x74\x6F\x6B\x65\x6E\x20\x3D\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00224)->A_0001E) == (NULL)));
      (A_002F1)(((u8 *)"\x32\x36\x36\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x6D\x74\x2E\x65\x78\x70\x72\x5F\x30\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x21\x3D\x20\x60\x6E\x6F\x64\x65\x20\x66\x75\x6E\x63\x74\x69\x6F\x6E\x20\x74\x79\x70\x65\x60\x29\x3B"), ((((A_00211)->A_0003B)->A_00039) != ((s64)0x43)));
      ((A_00224)->A_00020) = ((s64)0x3);
      ((A_00224)->A_00021) = ((s64)0x1);
      if (((A_00224)->A_0001B) == (NULL))
      {
        ((A_00224)->A_0001B) = ((A_00201)(((A_00223)->A_0003C), (&((A_00211)->A_00044))));
      }
    }
    if ((A_00211)->A_0003C)
    {
      (A_001CD)(((A_00211)->A_0003C), (&((A_00211)->A_00044)));
    }
    if ((A_00211)->A_0003D)
    {
      (A_001CD)(((A_00211)->A_0003D), (&((A_00211)->A_00044)));
    }
    (A_00214)(((A_00211)->A_0003E), (&((A_00211)->A_00044)), (A_00213));
  }
  else if ((A_00215) == ((s64)0x3))
  {
    (A_002EB)(((u8 *)"\x32\x36\x38\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x63\x75\x72\x72\x65\x6E\x74\x5F\x66\x75\x6E\x63\x74\x69\x6F\x6E\x5F\x73\x79\x6D\x62\x6F\x6C\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00213) != (NULL)));
    (A_002EB)(((u8 *)"\x32\x36\x38\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x63\x75\x72\x72\x65\x6E\x74\x5F\x66\x75\x6E\x63\x74\x69\x6F\x6E\x5F\x73\x79\x6D\x62\x6F\x6C\x2E\x74\x79\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00213)->A_0001B) != (NULL)));
    (A_002EB)(((u8 *)"\x32\x36\x38\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x63\x75\x72\x72\x65\x6E\x74\x5F\x66\x75\x6E\x63\x74\x69\x6F\x6E\x5F\x73\x79\x6D\x62\x6F\x6C\x2E\x74\x79\x70\x65\x2E\x73\x75\x62\x5F\x74\x79\x70\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((((A_00213)->A_0001B)->A_00013) != (NULL)));
    if ((A_00211)->A_0003B)
    {
      A_00031 A_00225/*rvalue*/ = {0};

      (A_00225) = ((A_001C8)(((A_001CD)(((A_00211)->A_0003B), (A_00212)))));
      if (!((A_001C5)((((A_00213)->A_0001B)->A_00013), ((A_00225).A_00033))))
      {
        (A_00293)(((s64)0x0), ((A_00225).A_00032), ((u8 *)"\x74\x68\x65\x20\x76\x61\x6C\x75\x65\x20\x63\x61\x6E\x27\x74\x20\x62\x65\x20\x69\x6D\x70\x6C\x69\x63\x69\x74\x6C\x79\x20\x63\x61\x73\x74\x20\x74\x6F\x20\x74\x68\x65\x20\x72\x65\x74\x75\x72\x6E\x20\x74\x79\x70\x65"));
      }
    }
  }
  else
  {
    (A_001CD)((A_00211), (A_00212));
  }
}

void A_00228/*scope_define_recursively*/(A_00038 (*A_00226/*node*/), A_0002C (*A_00227/*parent_scope*/))
{
  u64 A_00229/*node_kind*/ = 0;

  (A_00229) = ((A_00226)->A_00039);
  if (((A_00229) == ((s64)0x1)) || ((A_00229) == ((s64)0x2)))
  {
    A_00038 (*A_0022A/*scope_holder*/) = NULL;

    (A_0022A) = (A_00226);
    (A_0032F)((A_000F8), ((s64)0x8));
    (((A_0022A)->A_00044).A_0002D) = ((A_00321)((A_000F8)));
    (((A_0022A)->A_00044).A_0002F) = (A_00227);
    (A_0023F)((&((A_0022A)->A_00044)), ((A_00226)->A_00040), ((A_00226)->A_00041));
    {
      s64 A_0022B/*i*/ = 0;
      for (; (A_0022B) < ((A_00226)->A_00040); (A_0022B) += ((s64)0x1))
      {
        (A_00228)((((A_00226)->A_00041)[A_0022B]), (&((A_0022A)->A_00044)));
      }
    }
  }
  else if ((A_00229) == ((s64)0x9))
  {
    A_00038 (*A_0022C/*scope_holder*/) = NULL;

    (A_0022C) = (A_00226);
    (A_0032F)((A_000F8), ((s64)0x8));
    (((A_0022C)->A_00044).A_0002D) = ((A_00321)((A_000F8)));
    (((A_0022C)->A_00044).A_0002F) = (A_00227);
    if ((A_00226)->A_0003B)
    {
      (A_0023F)((&((A_0022C)->A_00044)), ((s64)0x1), (&((A_00226)->A_0003B)));
    }
    (A_00228)(((A_00226)->A_0003E), (&((A_0022C)->A_00044)));
  }
  else if ((A_00229) == ((s64)0x8))
  {
    (A_00228)(((A_00226)->A_0003E), (A_00227));
    if ((A_00226)->A_0003F)
    {
      (A_00228)(((A_00226)->A_0003F), (A_00227));
    }
  }
  else if ((A_00229) == ((s64)0x6))
  {
    (A_00228)(((A_00226)->A_0003E), (A_00227));
  }
  else if ((A_00229) == ((s64)0x7))
  {
    (A_00228)(((A_00226)->A_0003E), (A_00227));
  }
  else if ((((A_00229) == ((s64)0x22)) && ((((A_00226)->A_0003C)->A_00039) == ((s64)0x43))) && (((A_00226)->A_0003E) != (NULL)))
  {
    A_00038 (*A_0022D/*scope_holder*/) = NULL;

    (A_002EB)(((u8 *)"\x32\x37\x34\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6E\x6F\x64\x65\x2E\x73\x74\x6D\x74\x5F\x30\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x3D\x3D\x20\x60\x6E\x6F\x64\x65\x20\x73\x74\x61\x74\x65\x6D\x65\x6E\x74\x20\x6C\x69\x73\x74\x60\x29\x3B"), ((((A_00226)->A_0003E)->A_00039) == ((s64)0x2)));
    (A_0022D) = ((A_00226)->A_0003E);
    (A_0032F)((A_000F8), ((s64)0x8));
    (((A_0022D)->A_00044).A_0002D) = ((A_00321)((A_000F8)));
    (((A_0022D)->A_00044).A_0002F) = (A_00227);
    (A_0023F)((&((A_0022D)->A_00044)), (((A_00226)->A_0003C)->A_00040), (((A_00226)->A_0003C)->A_00041));
    (A_0023F)((&((A_0022D)->A_00044)), (((A_00226)->A_0003E)->A_00040), (((A_00226)->A_0003E)->A_00041));
    {
      s64 A_0022E/*i*/ = 0;
      for (; (A_0022E) < (((A_00226)->A_0003E)->A_00040); (A_0022E) += ((s64)0x1))
      {
        (A_00228)(((((A_00226)->A_0003E)->A_00041)[A_0022E]), (&((A_0022D)->A_00044)));
      }
    }
  }
}

A_00019 (*A_00233/*array_find_symbol_by_name*/(s64 A_0022F/*num_symptrs*/, A_00019 (*(*A_00230/*symptrs*/)), s64 A_00231/*name_length*/, u8 (*A_00232/*name*/)))
{
  {
    s64 A_00234/*symptr_index*/ = 0;
    for (; (A_00234) < (A_0022F); (A_00234) += ((s64)0x1))
    {
      A_00019 (*A_00235/*symbol*/) = NULL;

      (A_00235) = ((A_00230)[A_00234]);
      if (((((A_00235)->A_0001A)->A_00009) == (A_00231)) && ((A_002D1)((A_00232), (((A_00235)->A_0001A)->A_00008), (A_00231))))
      {
        return A_00235;
      }
    }
  }
  return NULL;
}

A_00019 (*A_00239/*scope_find_symbol_by_name*/(A_0002C (*A_00236/*current_scope*/), s64 A_00237/*name_length*/, u8 (*A_00238/*name*/)))
{
  A_0002C (*A_0023A/*scope*/) = NULL;

  (A_0023A) = (A_00236);
  {
    for (; (A_0023A) != (NULL); (A_0023A) = ((A_0023A)->A_0002F))
    {
      A_00019 (*A_0023B/*s*/) = NULL;

      (A_0023B) = ((A_00233)(((A_0023A)->A_0002E), ((A_0023A)->A_0002D), (A_00237), (A_00238)));
      if (A_0023B)
      {
        return A_0023B;
      }
    }
  }
  return NULL;
}

void A_0023F/*scope_append_declarations_from_list*/(A_0002C (*A_0023C/*scope*/), s64 A_0023D/*num_items*/, A_00038 (*(*A_0023E/*items*/)))
{
  {
    s64 A_00240/*i*/ = 0;
    for (; (A_00240) < (A_0023D); (A_00240) += ((s64)0x1))
    {
      A_00038 (*A_00241/*node*/) = NULL;

      (A_00241) = ((A_0023E)[A_00240]);
      if (((A_00241)->A_00039) == ((s64)0x22))
      {
        A_00019 (*A_00242/*symbol*/) = NULL;
        A_00019 (*A_00243/*prev*/) = NULL;

        (A_00242) = (((A_00241)->A_0003B)->A_00042);
        (A_002EB)(((u8 *)"\x32\x37\x39\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00242) != (NULL)));
        (A_00243) = ((A_00233)(((A_0023C)->A_0002E), ((A_0023C)->A_0002D), (((A_00242)->A_0001A)->A_00009), (((A_00242)->A_0001A)->A_00008)));
        if (A_00243)
        {
          (A_00293)(((s64)0x3), ((A_00242)->A_0001A), ((u8 *)"\x73\x79\x6D\x62\x6F\x6C\x20\x64\x65\x63\x6C\x61\x72\x65\x64\x20\x74\x77\x69\x63\x65\x20\x69\x6E\x20\x74\x68\x65\x20\x73\x61\x6D\x65\x20\x73\x63\x6F\x70\x65"));
          (A_00293)(((s64)0x1), ((A_00243)->A_0001A), ((u8 *)"\x68\x65\x72\x65\x20\x69\x73\x20\x61\x6E\x6F\x74\x68\x65\x72\x20\x64\x65\x63\x6C\x61\x72\x61\x74\x69\x6F\x6E"));
          (A_00367)((u32)((s64)0x1));
        }
        (A_00334)((A_000F8), ((s64)0x8), (&(A_00242)));
        ((A_0023C)->A_0002E) += ((s64)0x1);
      }
      else if (((A_00241)->A_00039) == ((s64)0x46))
      {
        {
          s64 A_00244/*ci*/ = 0;
          for (; (A_00244) < ((A_00241)->A_00040); (A_00244) += ((s64)0x1))
          {
            A_00038 (*A_00245/*name*/) = NULL;
            A_00019 (*A_00246/*symbol*/) = NULL;
            A_00019 (*A_00247/*prev*/) = NULL;

            (A_00245) = (((A_00241)->A_00041)[A_00244]);
            (A_00246) = ((A_00245)->A_00042);
            (A_002EB)(((u8 *)"\x32\x38\x31\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x79\x6D\x62\x6F\x6C\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00246) != (NULL)));
            (A_00247) = ((A_00233)(((A_0023C)->A_0002E), ((A_0023C)->A_0002D), (((A_00246)->A_0001A)->A_00009), (((A_00246)->A_0001A)->A_00008)));
            if (A_00247)
            {
              (A_00293)(((s64)0x3), ((A_00246)->A_0001A), ((u8 *)"\x73\x79\x6D\x62\x6F\x6C\x20\x64\x65\x63\x6C\x61\x72\x65\x64\x20\x74\x77\x69\x63\x65\x20\x69\x6E\x20\x74\x68\x65\x20\x73\x61\x6D\x65\x20\x73\x63\x6F\x70\x65"));
              (A_00293)(((s64)0x1), ((A_00247)->A_0001A), ((u8 *)"\x68\x65\x72\x65\x20\x69\x73\x20\x61\x6E\x6F\x74\x68\x65\x72\x20\x64\x65\x63\x6C\x61\x72\x61\x74\x69\x6F\x6E"));
              (A_00367)((u32)((s64)0x1));
            }
            ((A_00246)->A_0001B) = (&(A_000FC));
            ((A_00246)->A_00023) = (A_00244);
            ((A_00246)->A_00020) = ((s64)0x5);
            (A_00334)((A_000F8), ((s64)0x8), (&(A_00246)));
            ((A_0023C)->A_0002E) += ((s64)0x1);
          }
        }
      }
    }
  }
}

A_00038 (*A_0024A/*parse_expression*/(A_00025 (*A_00248/*parser*/), u64 A_00249/*minimal_precedence*/))
{
  A_00038 (*A_0024B/*lhs*/) = NULL;
  s64 A_0024C/*primary_kind*/ = 0;
  s64 A_0024D/*prefix_kind*/ = 0;
  u64 A_0024E/*prefix_precedence*/ = 0;

  (A_0024E) = ((s64)0x100);
  if ((A_00280)((A_00248), ((s64)0x4)))
  {
    (A_0024C) = ((s64)0xA);
  }
  else if ((A_00280)((A_00248), ((s64)0x15)))
  {
    (A_0024C) = ((s64)0xB);
  }
  else if ((A_00280)((A_00248), ((s64)0x14)))
  {
    (A_0024C) = ((s64)0xC);
  }
  else if ((A_00280)((A_00248), ((s64)0xA)))
  {
    (A_0024C) = ((s64)0xD);
  }
  else if ((A_00280)((A_00248), ((s64)0xB)))
  {
    (A_0024C) = ((s64)0xE);
  }
  else if ((A_00280)((A_00248), ((s64)0xC)))
  {
    (A_0024C) = ((s64)0xF);
  }
  else if ((A_00280)((A_00248), ((s64)0x5)))
  {
    (A_0024C) = ((s64)0x10);
  }
  else if ((A_00280)((A_00248), ((s64)0xD)))
  {
    (A_0024C) = ((s64)0x11);
  }
  else if ((A_00280)((A_00248), ((s64)0xE)))
  {
    (A_0024C) = ((s64)0x12);
  }
  else if ((A_00280)((A_00248), ((s64)0xF)))
  {
    (A_0024C) = ((s64)0x13);
  }
  else if ((A_00280)((A_00248), ((s64)0x6)))
  {
    (A_0024C) = ((s64)0x14);
  }
  else if ((A_00280)((A_00248), ((s64)0x27)))
  {
    (A_0024C) = ((s64)0x15);
  }
  else if ((A_00280)((A_00248), ((s64)0x1)))
  {
    (A_0024C) = ((s64)0x16);
  }
  else if ((A_00280)((A_00248), ((s64)0x3)))
  {
    (A_0024C) = ((s64)0x17);
  }
  else if ((A_00280)((A_00248), ((s64)0x3D)))
  {
    (A_0024D) = ((s64)0x19);
  }
  else if ((A_00280)((A_00248), ((s64)0x3E)))
  {
    (A_0024D) = ((s64)0x1A);
  }
  else if ((A_00280)((A_00248), ((s64)0x43)))
  {
    (A_0024D) = ((s64)0x1B);
  }
  else if ((A_00280)((A_00248), ((s64)0x3F)))
  {
    (A_0024D) = ((s64)0x1C);
  }
  else if ((A_00280)((A_00248), ((s64)0x13)))
  {
    (A_0024D) = ((s64)0x1D);
  }
  else if ((A_00280)((A_00248), ((s64)0x22)))
  {
    (A_0024D) = ((s64)0x1E);
  }
  else if ((A_00280)((A_00248), ((s64)0x29)))
  {
    (A_0024D) = ((s64)0x1F);
  }
  if (A_0024C)
  {
    (A_0027D)((A_00248));
    (A_0024B) = ((A_0028E)((A_0024C), ((A_002A4)((A_00248), (-((s64)0x1))))));
  }
  else if (A_0024D)
  {
    (A_0027D)((A_00248));
    (A_0024B) = ((A_0028E)((A_0024D), ((A_002A4)((A_00248), (-((s64)0x1))))));
    ((A_0024B)->A_0003B) = ((A_0024A)((A_00248), (A_0024E)));
  }
  else if ((A_00284)((A_00248), ((s64)0x25)))
  {
    A_00007 (*A_0024F/*the_string*/) = NULL;

    (A_0024F) = ((A_00289)((A_00248), ((s64)0x2), ((u8 *)"\x74\x68\x65\x20\x73\x74\x72\x69\x6E\x67\x20\x63\x6F\x6E\x73\x74\x61\x6E\x74\x20\x61\x66\x74\x65\x72\x20\x63\x5F\x73\x74\x72\x69\x6E\x67")));
    (A_0024B) = ((A_0028E)(((s64)0x18), (A_0024F)));
  }
  else if ((A_00284)((A_00248), ((s64)0x1F)))
  {
    void (*A_00250/*members*/) = NULL;

    (A_0024B) = ((A_0028E)(((s64)0x45), ((A_002A4)((A_00248), (-((s64)0x1))))));
    (A_000FA) += ((s64)0x1);
    ((A_0024B)->A_00045) = ((A_00321)((A_000F8)));
    (A_00276)((A_000F8), (A_000FA));
    (A_0032B)((A_000F8), ((s64)0x1));
    (A_00250) = ((A_00321)((A_000F9)));
    (A_00289)((A_00248), ((s64)0x4E), ((u8 *)"\x74\x68\x65\x20\x6F\x70\x65\x6E\x6E\x69\x6E\x67\x20\x63\x75\x72\x6C\x79\x20\x62\x72\x61\x63\x65\x20\x27\x7B\x27\x20\x6F\x66\x20\x74\x68\x65\x20\x73\x74\x72\x75\x63\x74"));
    while ((((A_002A1)((A_00248))) > ((s64)0x0)) && (!((A_00280)((A_00248), ((s64)0x4F)))))
    {
      A_00038 (*A_00251/*member*/) = NULL;

      (A_00251) = ((A_0024A)((A_00248), ((s64)0x0)));
      (A_00289)((A_00248), ((s64)0x48), ((u8 *)"\x74\x68\x65\x20\x73\x65\x6D\x69\x63\x6F\x6C\x6F\x6E\x20\x27\x3B\x27\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x6D\x65\x6D\x62\x65\x72\x20\x64\x65\x63\x6C\x61\x72\x61\x74\x69\x6F\x6E"));
      (A_00334)((A_000F9), ((s64)0x8), (&(A_00251)));
      ((A_0024B)->A_00040) += ((s64)0x1);
    }
    (A_00289)((A_00248), ((s64)0x4F), ((u8 *)"\x74\x68\x65\x20\x63\x6C\x6F\x73\x69\x6E\x67\x20\x63\x75\x72\x6C\x79\x20\x62\x72\x61\x63\x65\x20\x27\x7D\x27\x20\x6F\x66\x20\x74\x68\x65\x20\x73\x74\x72\x75\x63\x74"));
    (A_0032F)((A_000F8), ((s64)0x8));
    ((A_0024B)->A_00041) = ((A_00334)((A_000F8), (((A_0024B)->A_00040) * ((s64)0x8)), (A_00250)));
    (A_00338)((A_000F9), (A_00250));
  }
  else if ((A_00284)((A_00248), ((s64)0x24)))
  {
    A_00007 (*A_00252/*c_extern_token*/) = NULL;

    (A_00252) = ((A_002A4)((A_00248), (-((s64)0x1))));
    (A_0024B) = ((A_0024A)((A_00248), ((s64)0x0)));
    if (((A_0024B)->A_00039) != ((s64)0x22))
    {
      (A_00293)(((s64)0x0), ((A_0024B)->A_0003A), ((u8 *)"\x6E\x6F\x74\x20\x61\x20\x64\x65\x63\x6C\x61\x72\x61\x74\x69\x6F\x6E\x20\x61\x66\x74\x65\x72\x20\x63\x5F\x65\x78\x74\x65\x72\x6E"));
    }
    (A_002EB)(((u8 *)"\x32\x39\x32\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6C\x68\x73\x2E\x65\x78\x70\x72\x5F\x30\x2E\x73\x79\x6D\x62\x6F\x6C\x5F\x62\x79\x5F\x6E\x61\x6D\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((((A_0024B)->A_0003B)->A_00042) != (NULL)));
    ((((A_0024B)->A_0003B)->A_00042)->A_0001E) = (A_00252);
  }
  else if ((A_00284)((A_00248), ((s64)0x28)))
  {
    A_00007 (*A_00253/*c_typedef_token*/) = NULL;

    (A_00253) = ((A_002A4)((A_00248), (-((s64)0x1))));
    (A_0024B) = ((A_0024A)((A_00248), ((s64)0x0)));
    if (((A_0024B)->A_00039) != ((s64)0x22))
    {
      (A_00293)(((s64)0x0), ((A_0024B)->A_0003A), ((u8 *)"\x6E\x6F\x74\x20\x61\x20\x64\x65\x63\x6C\x61\x72\x61\x74\x69\x6F\x6E\x20\x61\x66\x74\x65\x72\x20\x63\x5F\x74\x79\x70\x65\x64\x65\x66"));
    }
    (A_002EB)(((u8 *)"\x32\x39\x33\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6C\x68\x73\x2E\x65\x78\x70\x72\x5F\x30\x2E\x73\x79\x6D\x62\x6F\x6C\x5F\x62\x79\x5F\x6E\x61\x6D\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((((A_0024B)->A_0003B)->A_00042) != (NULL)));
    ((((A_0024B)->A_0003B)->A_00042)->A_0001F) = (A_00253);
  }
  else if ((A_00284)((A_00248), ((s64)0x1E)))
  {
    A_00007 (*A_00254/*the_name*/) = NULL;

    (A_00254) = ((A_00289)((A_00248), ((s64)0x4), ((u8 *)"\x74\x68\x65\x20\x43\x20\x6E\x61\x6D\x65")));
    (A_0024B) = ((A_0024A)((A_00248), ((s64)0x0)));
    if (((A_0024B)->A_00039) != ((s64)0x22))
    {
      (A_00293)(((s64)0x0), ((A_0024B)->A_0003A), ((u8 *)"\x6E\x6F\x74\x20\x61\x20\x64\x65\x63\x6C\x61\x72\x61\x74\x69\x6F\x6E\x20\x61\x66\x74\x65\x72\x20\x63\x5F\x6E\x61\x6D\x65"));
    }
    (A_002EB)(((u8 *)"\x32\x39\x34\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6C\x68\x73\x2E\x65\x78\x70\x72\x5F\x30\x2E\x73\x79\x6D\x62\x6F\x6C\x5F\x62\x79\x5F\x6E\x61\x6D\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((((A_0024B)->A_0003B)->A_00042) != (NULL)));
    ((((A_0024B)->A_0003B)->A_00042)->A_0001D) = ((A_00321)((A_000F8)));
    (A_002F5)((A_000F8), ((A_00254)->A_00009), ((A_00254)->A_00008));
    (A_0032B)((A_000F8), ((s64)0x1));
  }
  else
  {
    A_00038 (*A_00255/*function*/) = NULL;
    A_00007 (*A_00256/*token*/) = NULL;

    (A_00256) = ((A_00289)((A_00248), ((s64)0x4C), ((u8 *)"\x61\x20\x70\x72\x69\x6D\x61\x72\x79\x20\x65\x78\x70\x72\x65\x73\x73\x69\x6F\x6E")));
    if ((A_00284)((A_00248), ((s64)0x4D)))
    {
      (A_00255) = ((A_0028E)(((s64)0x43), (A_00256)));
    }
    else
    {
      A_00038 (*A_00257/*param0_or_subexpr*/) = NULL;

      (A_00257) = ((A_0024A)((A_00248), ((s64)0x0)));
      if (((A_00257)->A_00039) == ((s64)0x22))
      {
        A_00038 (*A_00258/*param0*/) = NULL;
        void (*A_00259/*params*/) = NULL;

        (A_00255) = ((A_0028E)(((s64)0x43), (A_00256)));
        (A_00258) = (A_00257);
        (A_00259) = ((A_00334)((A_000F9), ((s64)0x8), (&(A_00258))));
        ((A_00255)->A_00040) = ((s64)0x1);
        while ((A_00284)((A_00248), ((s64)0x4B)))
        {
          A_00038 (*A_0025A/*param*/) = NULL;

          if ((A_00280)((A_00248), ((s64)0x4D)))
          {
            break;
          }
          (A_0025A) = ((A_0024A)((A_00248), ((s64)0x0)));
          (A_00334)((A_000F9), ((s64)0x8), (&(A_0025A)));
          ((A_00255)->A_00040) += ((s64)0x1);
        }
        (A_00289)((A_00248), ((s64)0x4D), ((u8 *)"\x74\x68\x65\x20\x63\x6C\x6F\x73\x69\x6E\x67\x20\x70\x61\x72\x65\x6E\x74\x68\x65\x73\x69\x73\x20\x27\x29\x27\x20\x6F\x66\x20\x74\x68\x65\x20\x66\x75\x6E\x63\x74\x69\x6F\x6E\x20\x74\x79\x70\x65"));
        (A_0032F)((A_000F8), ((s64)0x8));
        ((A_00255)->A_00041) = ((A_00334)((A_000F8), (((A_00255)->A_00040) * ((s64)0x8)), (A_00259)));
        (A_00338)((A_000F9), (A_00259));
      }
      else
      {
        (A_0024B) = (A_00257);
        (A_00289)((A_00248), ((s64)0x4D), ((u8 *)"\x74\x68\x65\x20\x63\x6C\x6F\x73\x69\x6E\x67\x20\x70\x61\x72\x65\x6E\x74\x68\x65\x73\x69\x73\x20\x27\x29\x27\x20\x6F\x66\x20\x74\x68\x65\x20\x73\x75\x62\x2D\x65\x78\x70\x72\x65\x73\x73\x69\x6F\x6E"));
      }
    }
    if (A_00255)
    {
      ((A_00255)->A_0003A) = ((A_00289)((A_00248), ((s64)0x3A), ((u8 *)"\x74\x68\x65\x20\x61\x72\x72\x6F\x77\x20\x27\x2D\x3E\x27\x20\x69\x6E\x20\x74\x68\x65\x20\x66\x75\x6E\x63\x74\x69\x6F\x6E\x20\x74\x79\x70\x65")));
      ((A_00255)->A_0003B) = ((A_0024A)((A_00248), ((s64)0x0)));
      (A_0024B) = (A_00255);
    }
  }
  {
    for (;;)
    {
      s64 A_0025B/*binary_kind*/ = 0;
      s64 A_0025C/*postfix_kind*/ = 0;
      u64 A_0025D/*precedence*/ = 0;
      u64 A_0025E/*right_to_left*/ = 0;

      if ((A_00280)((A_00248), ((s64)0x49)))
      {
        (A_0025B) = ((s64)0x2D);
        (A_0025D) = ((s64)0x110);
      }
      else if ((A_00280)((A_00248), ((s64)0x3D)))
      {
        (A_0025B) = ((s64)0x23);
        (A_0025D) = ((s64)0x70);
      }
      else if ((A_00280)((A_00248), ((s64)0x3E)))
      {
        (A_0025B) = ((s64)0x24);
        (A_0025D) = ((s64)0x70);
      }
      else if ((A_00280)((A_00248), ((s64)0x3F)))
      {
        (A_0025B) = ((s64)0x25);
        (A_0025D) = ((s64)0x70);
      }
      else if ((A_00280)((A_00248), ((s64)0x40)))
      {
        (A_0025B) = ((s64)0x26);
        (A_0025D) = ((s64)0x70);
      }
      else if ((A_00280)((A_00248), ((s64)0x41)))
      {
        (A_0025B) = ((s64)0x27);
        (A_0025D) = ((s64)0x70);
      }
      else if ((A_00280)((A_00248), ((s64)0x42)))
      {
        (A_0025B) = ((s64)0x28);
        (A_0025D) = ((s64)0x70);
      }
      else if ((A_00280)((A_00248), ((s64)0x43)))
      {
        (A_0025B) = ((s64)0x29);
        (A_0025D) = ((s64)0x70);
      }
      else if ((A_00280)((A_00248), ((s64)0x44)))
      {
        (A_0025B) = ((s64)0x2A);
        (A_0025D) = ((s64)0x70);
      }
      else if ((A_00280)((A_00248), ((s64)0x38)))
      {
        (A_0025B) = ((s64)0x2B);
        (A_0025D) = ((s64)0x70);
      }
      else if ((A_00280)((A_00248), ((s64)0x39)))
      {
        (A_0025B) = ((s64)0x2C);
        (A_0025D) = ((s64)0x70);
      }
      else if ((A_00280)((A_00248), ((s64)0x36)))
      {
        (A_0025B) = ((s64)0x2E);
        (A_0025D) = ((s64)0x60);
      }
      else if ((A_00280)((A_00248), ((s64)0x37)))
      {
        (A_0025B) = ((s64)0x2F);
        (A_0025D) = ((s64)0x60);
      }
      else if ((A_00280)((A_00248), ((s64)0x34)))
      {
        (A_0025B) = ((s64)0x30);
        (A_0025D) = ((s64)0x60);
      }
      else if ((A_00280)((A_00248), ((s64)0x35)))
      {
        (A_0025B) = ((s64)0x31);
        (A_0025D) = ((s64)0x60);
      }
      else if ((A_00280)((A_00248), ((s64)0x45)))
      {
        (A_0025B) = ((s64)0x32);
        (A_0025D) = ((s64)0x60);
      }
      else if ((A_00280)((A_00248), ((s64)0x46)))
      {
        (A_0025B) = ((s64)0x33);
        (A_0025D) = ((s64)0x60);
      }
      else if ((A_00280)((A_00248), ((s64)0x12)))
      {
        (A_0025B) = ((s64)0x35);
        (A_0025D) = ((s64)0x50);
      }
      else if ((A_00280)((A_00248), ((s64)0x7)))
      {
        (A_0025B) = ((s64)0x36);
        (A_0025D) = ((s64)0x40);
      }
      else if ((A_00280)((A_00248), ((s64)0x47)))
      {
        (A_0025B) = ((s64)0x37);
        (A_0025D) = ((s64)0x30);
        (A_0025E) = ((s64)0x1);
      }
      else if ((A_00280)((A_00248), ((s64)0x2C)))
      {
        (A_0025B) = ((s64)0x38);
        (A_0025D) = ((s64)0x30);
        (A_0025E) = ((s64)0x1);
      }
      else if ((A_00280)((A_00248), ((s64)0x2D)))
      {
        (A_0025B) = ((s64)0x39);
        (A_0025D) = ((s64)0x30);
        (A_0025E) = ((s64)0x1);
      }
      else if ((A_00280)((A_00248), ((s64)0x2E)))
      {
        (A_0025B) = ((s64)0x3A);
        (A_0025D) = ((s64)0x30);
        (A_0025E) = ((s64)0x1);
      }
      else if ((A_00280)((A_00248), ((s64)0x2F)))
      {
        (A_0025B) = ((s64)0x3B);
        (A_0025D) = ((s64)0x30);
        (A_0025E) = ((s64)0x1);
      }
      else if ((A_00280)((A_00248), ((s64)0x30)))
      {
        (A_0025B) = ((s64)0x3C);
        (A_0025D) = ((s64)0x30);
        (A_0025E) = ((s64)0x1);
      }
      else if ((A_00280)((A_00248), ((s64)0x31)))
      {
        (A_0025B) = ((s64)0x3D);
        (A_0025D) = ((s64)0x30);
        (A_0025E) = ((s64)0x1);
      }
      else if ((A_00280)((A_00248), ((s64)0x32)))
      {
        (A_0025B) = ((s64)0x3E);
        (A_0025D) = ((s64)0x30);
        (A_0025E) = ((s64)0x1);
      }
      else if ((A_00280)((A_00248), ((s64)0x33)))
      {
        (A_0025B) = ((s64)0x3F);
        (A_0025D) = ((s64)0x30);
        (A_0025E) = ((s64)0x1);
      }
      else if ((A_00280)((A_00248), ((s64)0x2A)))
      {
        (A_0025B) = ((s64)0x40);
        (A_0025D) = ((s64)0x30);
        (A_0025E) = ((s64)0x1);
      }
      else if ((A_00280)((A_00248), ((s64)0x2B)))
      {
        (A_0025B) = ((s64)0x41);
        (A_0025D) = ((s64)0x30);
        (A_0025E) = ((s64)0x1);
      }
      else if ((A_00280)((A_00248), ((s64)0x4A)))
      {
        (A_0025B) = ((s64)0x22);
        (A_0025D) = ((s64)0x10);
      }
      else if ((A_00280)((A_00248), ((s64)0x4C)))
      {
        (A_0025C) = ((s64)0x44);
        (A_0025D) = ((s64)0x110);
      }
      else if ((A_00280)((A_00248), ((s64)0x50)))
      {
        (A_0025C) = ((s64)0x34);
        (A_0025D) = ((s64)0x110);
      }
      else if ((A_00280)((A_00248), ((s64)0x3B)))
      {
        (A_0025C) = ((s64)0x20);
        (A_0025D) = ((s64)0x110);
      }
      else if ((A_00280)((A_00248), ((s64)0x3C)))
      {
        (A_0025C) = ((s64)0x21);
        (A_0025D) = ((s64)0x110);
      }
      if (((A_0025B) == ((s64)0x2D)) && ((((A_002A8)((A_00248), ((s64)0x1)))->A_0000A) == ((s64)0x18)))
      {
        A_00038 (*A_0025F/*new_lhs*/) = NULL;

        if ((A_0025D) < (A_00249))
        {
          break;
        }
        (A_0027D)((A_00248));
        (A_0027D)((A_00248));
        (A_0025F) = ((A_0028E)(((s64)0x42), ((A_002A4)((A_00248), (-((s64)0x1))))));
        ((A_0025F)->A_0003B) = (A_0024B);
        ((A_0025F)->A_0003C) = ((A_0024A)((A_00248), ((s64)0x200)));
        (A_0024B) = (A_0025F);
      }
      else if (A_0025B)
      {
        A_00038 (*A_00260/*new_lhs*/) = NULL;

        if ((A_0025D) < (A_00249))
        {
          break;
        }
        (A_0027D)((A_00248));
        (A_00260) = ((A_0028E)((A_0025B), ((A_002A4)((A_00248), (-((s64)0x1))))));
        ((A_00260)->A_0003B) = (A_0024B);
        ((A_00260)->A_0003C) = ((A_0024A)((A_00248), ((A_0025D) + (!(A_0025E)))));
        (A_0024B) = (A_00260);
        if ((A_0025B) == ((s64)0x22))
        {
          A_00019 (*A_00261/*symbol*/) = NULL;

          if ((((A_00260)->A_0003B)->A_00039) != ((s64)0xA))
          {
            (A_00293)(((s64)0x0), (((A_00260)->A_0003B)->A_0003A), ((u8 *)"\x6E\x6F\x74\x20\x61\x20\x6E\x61\x6D\x65\x20\x69\x6E\x20\x74\x68\x65\x20\x64\x65\x63\x6C\x61\x72\x61\x74\x69\x6F\x6E"));
          }
          (A_0032F)((A_000F8), ((s64)0x8));
          (A_00261) = ((A_0032B)((A_000F8), ((s64)0x50)));
          ((A_00261)->A_0001A) = (((A_00260)->A_0003B)->A_0003A);
          ((A_00261)->A_0001C) = (A_00260);
          (A_000FA) += ((s64)0x1);
          ((A_00261)->A_0001D) = ((A_00321)((A_000F8)));
          (A_00276)((A_000F8), (A_000FA));
          (A_0032B)((A_000F8), ((s64)0x1));
          (((A_00260)->A_0003B)->A_00042) = (A_00261);
        }
      }
      else if (A_0025C)
      {
        A_00038 (*A_00262/*new_lhs*/) = NULL;

        if ((A_0025D) < (A_00249))
        {
          break;
        }
        (A_0027D)((A_00248));
        (A_00262) = ((A_0028E)((A_0025C), ((A_002A4)((A_00248), (-((s64)0x1))))));
        ((A_00262)->A_0003B) = (A_0024B);
        (A_0024B) = (A_00262);
        if ((A_0025C) == ((s64)0x44))
        {
          void (*A_00263/*args*/) = NULL;
          u64 A_00264/*can_continue*/ = 0;

          (A_00263) = ((A_00321)((A_000F9)));
          (A_00264) = ((s64)0x1);
          while (((((A_002A1)((A_00248))) > ((s64)0x0)) && (!((A_00280)((A_00248), ((s64)0x4D))))) && (A_00264))
          {
            A_00038 (*A_00265/*arg*/) = NULL;

            (A_00265) = ((A_0024A)((A_00248), ((s64)0x0)));
            (A_00334)((A_000F9), ((s64)0x8), (&(A_00265)));
            ((A_00262)->A_00040) += ((s64)0x1);
            (A_00264) = (((A_00284)((A_00248), ((s64)0x4B))) != (NULL));
          }
          (A_00289)((A_00248), ((s64)0x4D), ((u8 *)"\x74\x68\x65\x20\x63\x6C\x6F\x73\x69\x6E\x67\x20\x70\x61\x72\x65\x6E\x74\x68\x65\x73\x69\x73\x20\x27\x29\x27\x20\x6F\x66\x20\x74\x68\x65\x20\x66\x75\x6E\x63\x74\x69\x6F\x6E\x20\x63\x61\x6C\x6C"));
          (A_0032F)((A_000F8), ((s64)0x8));
          ((A_00262)->A_00041) = ((A_00334)((A_000F8), (((A_00262)->A_00040) * ((s64)0x8)), (A_00263)));
          (A_00338)((A_000F9), (A_00263));
        }
        else if ((A_0025C) == ((s64)0x34))
        {
          ((A_00262)->A_0003C) = ((A_0024A)((A_00248), ((s64)0x0)));
          (A_002F1)(((u8 *)"\x33\x31\x32\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6E\x65\x77\x5F\x6C\x68\x73\x2E\x65\x78\x70\x72\x5F\x31\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x21\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), ((((A_00262)->A_0003C)->A_00039) != ((s64)0x22)));
          (A_00289)((A_00248), ((s64)0x51), ((u8 *)"\x74\x68\x65\x20\x63\x6C\x6F\x73\x69\x6E\x67\x20\x62\x72\x61\x63\x6B\x65\x74\x20\x27\x5D\x27\x20\x6F\x66\x20\x74\x68\x65\x20\x69\x6E\x64\x65\x78\x20\x6F\x70\x65\x72\x61\x74\x6F\x72"));
        }
      }
      else
      {
        break;
      }
    }
  }
  (A_002EB)(((u8 *)"\x33\x31\x33\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6C\x68\x73\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0024B) != (NULL)));
  return A_0024B;
}

void A_00267/*ast_debug_print_to_console_error*/(A_00038 (*A_00266/*root*/))
{
  u8 (*A_00268/*string*/) = NULL;

  (A_00268) = ((A_00321)((A_000F9)));
  (A_002F8)((A_000F9), ((u8 *)"\x20\x20\x41\x53\x54\x3A\x0A"));
  (A_0026E)((A_00266), ((s64)0x0), ((u8 *)"\x72\x6F\x6F\x74"), (-((s64)0x1)), (A_000F9));
  (A_002F8)((A_000F9), ((u8 *)"\x0A\x0A"));
  (A_0032B)((A_000F9), ((s64)0x1));
  (A_0036C)((A_00268));
  (A_00338)((A_000F9), (A_00268));
}

void A_0026E/*ast_debug_print_recursively*/(A_00038 (*A_00269/*node*/), u64 A_0026A/*spaces*/, u8 (*A_0026B/*title*/), s64 A_0026C/*index_opt*/, A_00001 (*A_0026D/*result_arena*/))
{
  u64 A_0026F/*sub_spaces*/ = 0;

  (A_002FC)((A_0026D), (A_0026A), (u32)((s64)0x20));
  if ((A_0026C) >= ((s64)0x0))
  {
    (A_002F8)((A_0026D), ((u8 *)"\x5B"));
    (A_0030D)((A_0026D), (A_0026C), ((s64)0xA), ((s64)0x2));
    (A_002F8)((A_0026D), ((u8 *)"\x5D\x20\x20"));
  }
  (A_002F8)((A_0026D), (A_0026B));
  (A_002F8)((A_0026D), ((u8 *)"\x20\x20"));
  if ((A_00269) != (NULL))
  {
    if (((A_00269)->A_00039) != ((s64)0x0))
    {
      (A_002F8)((A_0026D), ((A_002AC)(((A_00269)->A_00039))));
      (A_002F8)((A_0026D), ((u8 *)"\x20\x20"));
    }
    else
    {
      (A_002F8)((A_0026D), ((u8 *)"\x28\x61\x73\x74\x2D\x3E\x6B\x69\x6E\x64\x20\x3D\x3D\x20\x30\x29\x20\x20"));
    }
    if ((((A_00269)->A_00044).A_0002D) != (NULL))
    {
      (A_002F8)((A_0026D), ((u8 *)"\x73\x79\x6D\x62\x6F\x6C\x73\x5B"));
      (A_0030D)((A_0026D), (((A_00269)->A_00044).A_0002E), ((s64)0xA), ((s64)0x0));
      (A_002F8)((A_0026D), ((u8 *)"\x5D\x20\x20"));
    }
    if (((A_00269)->A_00041) != (NULL))
    {
      (A_002F8)((A_0026D), ((u8 *)"\x69\x74\x65\x6D\x73\x5B"));
      (A_0030D)((A_0026D), ((A_00269)->A_00040), ((s64)0xA), ((s64)0x0));
      (A_002F8)((A_0026D), ((u8 *)"\x5D\x20\x20"));
    }
    (A_002F8)((A_0026D), ((u8 *)"\x7B\x20"));
    if (((A_00269)->A_0003A) != (NULL))
    {
      if (((((A_00269)->A_0003A)->A_00008) != (NULL)) && ((((A_00269)->A_0003A)->A_00009) >= ((s64)0x0)))
      {
        (A_002F8)((A_0026D), ((u8 *)"\x27"));
        (A_002F5)((A_0026D), (((A_00269)->A_0003A)->A_00009), (((A_00269)->A_0003A)->A_00008));
        (A_002F8)((A_0026D), ((u8 *)"\x27\x20"));
      }
      else
      {
        (A_002F8)((A_0026D), ((u8 *)"\x28\x6E\x6F\x64\x65\x2E\x74\x6F\x6B\x65\x6E\x20\x69\x73\x20\x69\x6E\x76\x61\x6C\x69\x64\x20"));
      }
      if ((((A_00269)->A_0003A)->A_0000A) == ((s64)0x0))
      {
        (A_002F8)((A_0026D), ((u8 *)"\x28\x6E\x6F\x64\x65\x2E\x74\x6F\x6B\x65\x6E\x2E\x74\x6F\x6B\x65\x6E\x5F\x6B\x69\x6E\x64\x20\x3D\x3D\x20\x30\x29"));
      }
    }
    else
    {
      (A_002F8)((A_0026D), ((u8 *)"\x28\x6E\x6F\x64\x65\x2E\x74\x6F\x6B\x65\x6E\x20\x3D\x3D\x20\x4E\x55\x4C\x4C\x29"));
    }
    (A_002F8)((A_0026D), ((u8 *)"\x20\x7D\x20\x20"));
  }
  else
  {
    (A_002F8)((A_0026D), ((u8 *)"\x28\x6E\x6F\x64\x65\x20\x3D\x3D\x20\x4E\x55\x4C\x4C\x29\x20\x20"));
  }
  (A_002F8)((A_0026D), ((u8 *)"\x0A"));
  (A_0026F) = ((A_0026A) + ((s64)0x4));
  if (((A_00269) != (NULL)) && (((A_00269)->A_00042) != (NULL)))
  {
    A_00019 (*A_00270/*symbol*/) = NULL;

    (A_00270) = ((A_00269)->A_00042);
    (A_002FC)((A_0026D), (A_0026F), (u32)((s64)0x20));
    (A_002F8)((A_0026D), ((u8 *)"\x73\x79\x6D\x62\x6F\x6C\x5F\x62\x79\x5F\x6E\x61\x6D\x65\x20\x20"));
    (A_002F5)((A_0026D), (((A_00270)->A_0001A)->A_00009), (((A_00270)->A_0001A)->A_00008));
    (A_002F8)((A_0026D), ((u8 *)"\x20\x20"));
    (A_002F8)((A_0026D), ((A_00270)->A_0001D));
    (A_002F8)((A_0026D), ((u8 *)"\x0A"));
  }
  if ((A_00269) != (NULL))
  {
    if ((((A_00269)->A_00044).A_0002D) != (NULL))
    {
      {
        s64 A_00271/*i*/ = 0;
        for (; (A_00271) < (((A_00269)->A_00044).A_0002E); (A_00271) += ((s64)0x1))
        {
          A_00019 (*A_00272/*symbol*/) = NULL;

          (A_00272) = ((((A_00269)->A_00044).A_0002D)[A_00271]);
          (A_002FC)((A_0026D), (A_0026F), (u32)((s64)0x20));
          (A_002F8)((A_0026D), ((u8 *)"\x73\x79\x6D\x62\x6F\x6C\x20\x5B"));
          (A_0030D)((A_0026D), (A_00271), ((s64)0xA), ((s64)0x2));
          (A_002F8)((A_0026D), ((u8 *)"\x5D\x20\x20"));
          (A_002F5)((A_0026D), (((A_00272)->A_0001A)->A_00009), (((A_00272)->A_0001A)->A_00008));
          (A_002F8)((A_0026D), ((u8 *)"\x20\x20"));
          (A_002F8)((A_0026D), ((A_00272)->A_0001D));
          (A_002F8)((A_0026D), ((u8 *)"\x0A"));
        }
      }
    }
    if (((A_00269)->A_0003B) != (NULL))
    {
      (A_0026E)(((A_00269)->A_0003B), (A_0026F), ((u8 *)"\x65\x78\x70\x72\x5F\x30"), (-((s64)0x1)), (A_0026D));
    }
    if (((A_00269)->A_0003C) != (NULL))
    {
      (A_0026E)(((A_00269)->A_0003C), (A_0026F), ((u8 *)"\x65\x78\x70\x72\x5F\x31"), (-((s64)0x1)), (A_0026D));
    }
    if (((A_00269)->A_0003D) != (NULL))
    {
      (A_0026E)(((A_00269)->A_0003D), (A_0026F), ((u8 *)"\x65\x78\x70\x72\x5F\x32"), (-((s64)0x1)), (A_0026D));
    }
    if (((A_00269)->A_0003E) != (NULL))
    {
      (A_0026E)(((A_00269)->A_0003E), (A_0026F), ((u8 *)"\x73\x74\x6D\x74\x5F\x30"), (-((s64)0x1)), (A_0026D));
    }
    if (((A_00269)->A_0003F) != (NULL))
    {
      (A_0026E)(((A_00269)->A_0003F), (A_0026F), ((u8 *)"\x73\x74\x6D\x74\x5F\x31"), (-((s64)0x1)), (A_0026D));
    }
    if (((A_00269)->A_00041) != (NULL))
    {
      {
        s64 A_00273/*i*/ = 0;
        for (; (A_00273) < ((A_00269)->A_00040); (A_00273) += ((s64)0x1))
        {
          (A_0026E)((((A_00269)->A_00041)[A_00273]), (A_0026F), ((u8 *)"\x69\x74\x65\x6D"), (A_00273), (A_0026D));
        }
      }
    }
  }
}

void A_00276/*arena_print_address*/(A_00001 (*A_00274/*arena*/), s64 A_00275/*address*/)
{
  (A_002F8)((A_00274), ((u8 *)"\x41\x5F"));
  (A_00302)((A_00274), (A_00275), ((s64)0x10), ((s64)0x5));
}

A_00038 (*A_00278/*parse_statement*/(A_00025 (*A_00277/*parser*/)))
{
  A_00038 (*A_00279/*stmt*/) = NULL;

  if ((A_00284)((A_00277), ((s64)0x4E)))
  {
    void (*A_0027A/*sub_stmts*/) = NULL;

    (A_00279) = ((A_0028E)(((s64)0x2), ((A_002A4)((A_00277), (-((s64)0x1))))));
    (A_0027A) = ((A_00321)((A_000F9)));
    while ((((A_002A1)((A_00277))) > ((s64)0x0)) && (!((A_00280)((A_00277), ((s64)0x4F)))))
    {
      A_00038 (*A_0027B/*sub_stmt*/) = NULL;

      (A_0027B) = ((A_00278)((A_00277)));
      (A_00334)((A_000F9), ((s64)0x8), (&(A_0027B)));
      ((A_00279)->A_00040) += ((s64)0x1);
    }
    (A_00289)((A_00277), ((s64)0x4F), ((u8 *)"\x74\x68\x65\x20\x63\x6C\x6F\x73\x69\x6E\x67\x20\x63\x75\x72\x6C\x79\x20\x62\x72\x61\x63\x65\x20\x27\x7D\x27\x20\x66\x6F\x72\x20\x74\x68\x65\x20\x73\x74\x61\x74\x65\x6D\x65\x6E\x74\x20\x6C\x69\x73\x74"));
    (A_0032F)((A_000F8), ((s64)0x8));
    ((A_00279)->A_00041) = ((A_00334)((A_000F8), (((A_00279)->A_00040) * ((s64)0x8)), (A_0027A)));
    (A_00338)((A_000F9), (A_0027A));
  }
  else if ((A_00284)((A_00277), ((s64)0x8)))
  {
    (A_00279) = ((A_0028E)(((s64)0x8), ((A_002A4)((A_00277), (-((s64)0x1))))));
    ((A_00279)->A_0003B) = ((A_0024A)((A_00277), ((s64)0x0)));
    ((A_00279)->A_0003E) = ((A_00278)((A_00277)));
    (A_002F1)(((u8 *)"\x33\x33\x30\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x6D\x74\x2E\x73\x74\x6D\x74\x5F\x30\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x21\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), ((((A_00279)->A_0003E)->A_00039) != ((s64)0x22)));
    if ((A_00284)((A_00277), ((s64)0x16)))
    {
      ((A_00279)->A_0003F) = ((A_00278)((A_00277)));
      (A_002F1)(((u8 *)"\x33\x33\x31\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x6D\x74\x2E\x73\x74\x6D\x74\x5F\x31\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x21\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), ((((A_00279)->A_0003F)->A_00039) != ((s64)0x22)));
    }
  }
  else if ((A_00284)((A_00277), ((s64)0x19)))
  {
    (A_00279) = ((A_0028E)(((s64)0x6), ((A_002A4)((A_00277), (-((s64)0x1))))));
    ((A_00279)->A_0003B) = ((A_0024A)((A_00277), ((s64)0x0)));
    ((A_00279)->A_0003E) = ((A_00278)((A_00277)));
    (A_002F1)(((u8 *)"\x33\x33\x31\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x6D\x74\x2E\x73\x74\x6D\x74\x5F\x30\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x21\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), ((((A_00279)->A_0003E)->A_00039) != ((s64)0x22)));
  }
  else if ((A_00284)((A_00277), ((s64)0x9)))
  {
    (A_00279) = ((A_0028E)(((s64)0x7), ((A_002A4)((A_00277), (-((s64)0x1))))));
    ((A_00279)->A_0003E) = ((A_00278)((A_00277)));
    (A_002F1)(((u8 *)"\x33\x33\x32\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x6D\x74\x2E\x73\x74\x6D\x74\x5F\x30\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x21\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), ((((A_00279)->A_0003E)->A_00039) != ((s64)0x22)));
    (A_00289)((A_00277), ((s64)0x19), ((u8 *)"\x74\x68\x65\x20\x27\x77\x68\x69\x6C\x65\x27\x20\x6B\x65\x79\x77\x6F\x72\x64\x20\x69\x6E\x20\x74\x68\x65\x20\x64\x6F\x2D\x77\x68\x69\x6C\x65\x20\x6C\x6F\x6F\x70"));
    ((A_00279)->A_0003B) = ((A_0024A)((A_00277), ((s64)0x0)));
    (A_00289)((A_00277), ((s64)0x48), ((u8 *)"\x74\x68\x65\x20\x73\x65\x6D\x69\x63\x6F\x6C\x6F\x6E\x20\x27\x3B\x27\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x63\x6F\x6E\x64\x69\x74\x69\x6F\x6E"));
  }
  else if ((A_00284)((A_00277), ((s64)0x1C)))
  {
    (A_00279) = ((A_0028E)(((s64)0x9), ((A_002A4)((A_00277), (-((s64)0x1))))));
    if (!((A_00280)((A_00277), ((s64)0x48))))
    {
      ((A_00279)->A_0003B) = ((A_0024A)((A_00277), ((s64)0x0)));
      (A_002F1)(((u8 *)"\x33\x33\x33\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x6D\x74\x2E\x65\x78\x70\x72\x5F\x30\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x3D\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), ((((A_00279)->A_0003B)->A_00039) == ((s64)0x22)));
    }
    (A_00289)((A_00277), ((s64)0x48), ((u8 *)"\x74\x68\x65\x20\x73\x65\x6D\x69\x63\x6F\x6C\x6F\x6E\x20\x27\x3B\x27\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x69\x6E\x69\x74\x20\x69\x6E\x20\x63\x5F\x66\x6F\x72"));
    if (!((A_00280)((A_00277), ((s64)0x48))))
    {
      ((A_00279)->A_0003C) = ((A_0024A)((A_00277), ((s64)0x0)));
      (A_002F1)(((u8 *)"\x33\x33\x34\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x6D\x74\x2E\x65\x78\x70\x72\x5F\x31\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x21\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), ((((A_00279)->A_0003C)->A_00039) != ((s64)0x22)));
    }
    (A_00289)((A_00277), ((s64)0x48), ((u8 *)"\x74\x68\x65\x20\x73\x65\x6D\x69\x63\x6F\x6C\x6F\x6E\x20\x27\x3B\x27\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x63\x6F\x6E\x64\x69\x74\x69\x6F\x6E\x20\x69\x6E\x20\x63\x5F\x66\x6F\x72"));
    if (!((A_00280)((A_00277), ((s64)0x48))))
    {
      ((A_00279)->A_0003D) = ((A_0024A)((A_00277), ((s64)0x0)));
      (A_002F1)(((u8 *)"\x33\x33\x35\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x6D\x74\x2E\x65\x78\x70\x72\x5F\x32\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x21\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), ((((A_00279)->A_0003D)->A_00039) != ((s64)0x22)));
    }
    (A_00289)((A_00277), ((s64)0x48), ((u8 *)"\x74\x68\x65\x20\x73\x65\x6D\x69\x63\x6F\x6C\x6F\x6E\x20\x27\x3B\x27\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x72\x65\x69\x6E\x69\x74\x20\x69\x6E\x20\x63\x5F\x66\x6F\x72"));
    ((A_00279)->A_0003E) = ((A_00278)((A_00277)));
    (A_002F1)(((u8 *)"\x33\x33\x36\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x6D\x74\x2E\x73\x74\x6D\x74\x5F\x30\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x21\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), ((((A_00279)->A_0003E)->A_00039) != ((s64)0x22)));
  }
  else if ((A_00284)((A_00277), ((s64)0x1A)))
  {
    (A_00279) = ((A_0028E)(((s64)0x4), ((A_002A4)((A_00277), (-((s64)0x1))))));
    (A_00289)((A_00277), ((s64)0x48), ((u8 *)"\x74\x68\x65\x20\x73\x65\x6D\x69\x63\x6F\x6C\x6F\x6E\x20\x27\x3B\x27\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x62\x72\x65\x61\x6B"));
  }
  else if ((A_00284)((A_00277), ((s64)0x26)))
  {
    (A_00279) = ((A_0028E)(((s64)0x5), ((A_002A4)((A_00277), (-((s64)0x1))))));
    (A_00289)((A_00277), ((s64)0x48), ((u8 *)"\x74\x68\x65\x20\x73\x65\x6D\x69\x63\x6F\x6C\x6F\x6E\x20\x27\x3B\x27\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x63\x6F\x6E\x74\x69\x6E\x75\x65"));
  }
  else if ((A_00284)((A_00277), ((s64)0x1D)))
  {
    (A_00279) = ((A_0028E)(((s64)0x3), ((A_002A4)((A_00277), (-((s64)0x1))))));
    ((A_00279)->A_0003B) = ((A_0024A)((A_00277), ((s64)0x0)));
    (A_002F1)(((u8 *)"\x33\x33\x37\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x6D\x74\x2E\x65\x78\x70\x72\x5F\x30\x2E\x6E\x6F\x64\x65\x5F\x6B\x69\x6E\x64\x20\x21\x3D\x20\x60\x6E\x6F\x64\x65\x20\x62\x69\x6E\x61\x72\x79\x20\x3A\x60\x29\x3B"), ((((A_00279)->A_0003B)->A_00039) != ((s64)0x22)));
    (A_00289)((A_00277), ((s64)0x48), ((u8 *)"\x74\x68\x65\x20\x73\x65\x6D\x69\x63\x6F\x6C\x6F\x6E\x20\x27\x3B\x27\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x72\x65\x74\x75\x72\x6E"));
  }
  else
  {
    (A_00279) = ((A_0024A)((A_00277), ((s64)0x0)));
    (A_00289)((A_00277), ((s64)0x48), ((u8 *)"\x74\x68\x65\x20\x73\x65\x6D\x69\x63\x6F\x6C\x6F\x6E\x20\x27\x3B\x27\x20\x61\x66\x74\x65\x72\x20\x74\x68\x65\x20\x65\x78\x70\x72\x65\x73\x73\x69\x6F\x6E"));
  }
  (A_002EB)(((u8 *)"\x33\x33\x38\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x74\x6D\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00279) != (NULL)));
  return A_00279;
}

void A_0027D/*parser_proceed*/(A_00025 (*A_0027C/*parser*/))
{
  (A_002EB)(((u8 *)"\x33\x33\x39\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x70\x61\x72\x73\x65\x72\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0027C) != (NULL)));
  if (((A_0027C)->A_0002A) < ((A_0027C)->A_00029))
  {
    ((A_0027C)->A_0002A) += ((s64)0x1);
  }
}

A_00007 (*A_00280/*parser_inspect*/(A_00025 (*A_0027E/*parser*/), s64 A_0027F/*token_kind*/))
{
  A_00007 (*A_00281/*curr*/) = NULL;

  (A_002EB)(((u8 *)"\x33\x34\x30\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x70\x61\x72\x73\x65\x72\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0027E) != (NULL)));
  (A_00281) = ((A_002A8)((A_0027E), ((s64)0x0)));
  if (((A_00281)->A_0000A) != (A_0027F))
  {
    return NULL;
  }
  return A_00281;
}

A_00007 (*A_00284/*parser_accept*/(A_00025 (*A_00282/*parser*/), s64 A_00283/*token_kind*/))
{
  A_00007 (*A_00285/*curr*/) = NULL;

  (A_002EB)(((u8 *)"\x33\x34\x31\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x70\x61\x72\x73\x65\x72\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00282) != (NULL)));
  (A_00285) = ((A_002A8)((A_00282), ((s64)0x0)));
  if (((A_00285)->A_0000A) != (A_00283))
  {
    return NULL;
  }
  (A_0027D)((A_00282));
  return A_00285;
}

A_00007 (*A_00289/*parser_expect*/(A_00025 (*A_00286/*parser*/), s64 A_00287/*token_kind*/, u8 (*A_00288/*what*/)))
{
  A_00007 (*A_0028A/*curr*/) = NULL;

  (A_002EB)(((u8 *)"\x33\x34\x32\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x70\x61\x72\x73\x65\x72\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00286) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x34\x32\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x77\x68\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00288) != (NULL)));
  (A_0028A) = ((A_002A8)((A_00286), ((s64)0x0)));
  if (((A_0028A)->A_0000A) != (A_00287))
  {
    u8 (*A_0028B/*message*/) = NULL;

    (A_0028B) = ((A_00321)((A_000F9)));
    (A_002F8)((A_000F9), ((u8 *)"\x65\x78\x70\x65\x63\x74\x65\x64\x20"));
    (A_002F8)((A_000F9), (A_00288));
    (A_0032B)((A_000F9), ((s64)0x1));
    (A_00293)(((s64)0x0), (A_0028A), (A_0028B));
    (A_00338)((A_000F9), (A_0028B));
  }
  (A_0027D)((A_00286));
  return A_0028A;
}

A_00038 (*A_0028E/*ast_create_node*/(s64 A_0028C/*node_kind_opt*/, A_00007 (*A_0028D/*token_opt*/)))
{
  A_00038 (*A_0028F/*result*/) = NULL;

  (A_0032F)((A_000F8), ((s64)0x8));
  (A_0028F) = ((A_0032B)((A_000F8), ((s64)0x98)));
  ((A_0028F)->A_00039) = (A_0028C);
  ((A_0028F)->A_0003A) = (A_0028D);
  return A_0028F;
}

void A_00293/*complain*/(s64 A_00290/*complain_kind*/, A_00007 (*A_00291/*token_opt*/), u8 (*A_00292/*message*/))
{
  A_00001 (*A_00294/*text_arena*/) = NULL;
  u8 (*A_00295/*text*/) = NULL;
  s64 A_00296/*row*/ = 0;
  s64 A_00297/*col*/ = 0;
  u8 (*A_00299/*kind_as_color*/) = NULL;
  u8 (*A_0029A/*kind_as_cstring*/) = NULL;

  (A_002EB)(((u8 *)"\x33\x34\x35\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6D\x65\x73\x73\x61\x67\x65\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00292) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x34\x35\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x63\x6F\x6D\x70\x6C\x61\x69\x6E\x5F\x6B\x69\x6E\x64\x20\x3C\x20\x43\x4F\x4D\x50\x4C\x41\x49\x4E\x5F\x45\x4E\x55\x4D\x5F\x43\x4F\x55\x4E\x54\x29\x3B"), ((A_00290) < ((s64)0x4)));
  (A_00294) = (A_000F9);
  (A_00295) = ((A_00321)((A_00294)));
  if (A_00291)
  {
    (A_00296) = ((s64)0x1);
    (A_00297) = ((s64)0x1);
    {
      s64 A_00298/*i*/ = 0;
      for (; (((A_00291)->A_0000B) + (A_00298)) != ((A_00291)->A_00008); (A_00298) += ((s64)0x1))
      {
        if ((((A_00291)->A_0000B)[A_00298]) == ((s64)0xA))
        {
          (A_00296) += ((s64)0x1);
          (A_00297) = ((s64)0x0);
        }
        (A_00297) += ((s64)0x1);
      }
    }
    (A_002F8)((A_00294), ((u8 *)"\x1B\x5B\x39\x33\x6D"));
    (A_0030D)((A_00294), (A_00296), ((s64)0xA), ((s64)0x0));
    (A_002F8)((A_00294), ((u8 *)"\x3A"));
    (A_0030D)((A_00294), (A_00297), ((s64)0xA), ((s64)0x0));
    (A_002F8)((A_00294), ((u8 *)"\x3A\x20"));
  }
  if (((A_00290) == ((s64)0x3)) || ((A_00290) == ((s64)0x0)))
  {
    (A_00299) = ((u8 *)"\x1B\x5B\x39\x31\x6D");
    (A_0029A) = ((u8 *)"\x1B\x5B\x39\x31\x6D\x65\x72\x72\x6F\x72\x3A\x1B\x5B\x30\x6D");
  }
  else if ((A_00290) == ((s64)0x1))
  {
    (A_00299) = ((u8 *)"\x1B\x5B\x39\x36\x6D");
    (A_0029A) = ((u8 *)"\x1B\x5B\x39\x36\x6D\x6E\x6F\x74\x65\x3A\x1B\x5B\x30\x6D");
  }
  else if ((A_00290) == ((s64)0x2))
  {
    (A_00299) = ((u8 *)"\x1B\x5B\x39\x35\x6D");
    (A_0029A) = ((u8 *)"\x1B\x5B\x39\x35\x6D\x77\x61\x72\x6E\x69\x6E\x67\x3A\x1B\x5B\x30\x6D");
  }
  (A_002F8)((A_00294), (A_0029A));
  (A_002F8)((A_00294), ((u8 *)"\x20"));
  (A_002F8)((A_00294), (A_00292));
  (A_002F8)((A_00294), ((u8 *)"\x0A"));
  if (A_00291)
  {
    s64 A_0029B/*size_0*/ = 0;
    u8 (*A_0029C/*line*/) = NULL;
    s64 A_0029D/*line_size*/ = 0;
    s64 A_0029E/*size_1*/ = 0;
    s64 A_0029F/*size_2*/ = 0;

    (A_002F8)((A_00294), ((u8 *)"\x20"));
    (A_0029B) = ((A_0030D)((A_00294), (A_00296), ((s64)0xA), ((s64)0x0)));
    (A_002F8)((A_00294), ((u8 *)"\x20\x7C\x20"));
    (A_0029C) = (((A_00291)->A_00008) - ((A_00297) - ((s64)0x1)));
    while ((((A_0029C)[A_0029D]) != ((s64)0x0)) && (((A_0029C)[A_0029D]) != ((s64)0xA)))
    {
      (A_0029D) += ((s64)0x1);
    }
    (A_0029E) = ((A_002F5)((A_00294), ((A_00297) - ((s64)0x1)), (A_0029C)));
    (A_002F8)((A_00294), (A_00299));
    (A_0029F) = ((A_002F5)((A_00294), ((A_00291)->A_00009), ((A_00291)->A_00008)));
    (A_002F8)((A_00294), ((u8 *)"\x1B\x5B\x30\x6D"));
    (A_002F5)((A_00294), ((A_0029D) - ((A_0029E) + (A_0029F))), ((A_0029C) + ((A_0029E) + (A_0029F))));
    (A_002F8)((A_00294), ((u8 *)"\x0A"));
    (A_002FC)((A_00294), ((A_0029B) + ((s64)0x2)), (u32)((s64)0x20));
    (A_002F8)((A_00294), ((u8 *)"\x7C"));
    (A_002FC)((A_00294), (A_00297), (u32)((s64)0x20));
    (A_002F8)((A_00294), (A_00299));
    (A_002F8)((A_00294), ((u8 *)"\x5E"));
    if (((A_00291)->A_00009) > ((s64)0x1))
    {
      (A_002FC)((A_00294), (((A_00291)->A_00009) - ((s64)0x1)), (u32)((s64)0x7E));
    }
    (A_002F8)((A_00294), ((u8 *)"\x1B\x5B\x30\x6D\x0A"));
  }
  (A_0036A)((((u8 (*))((A_00321)((A_00294)))) - (A_00295)), (A_00295));
  (A_00338)((A_00294), (A_00295));
  if ((A_00290) == ((s64)0x0))
  {
    (A_00367)((u32)((s64)0x1));
  }
}

s64 A_002A1/*parser_tokens_left*/(A_00025 (*A_002A0/*parser*/))
{
  (A_002EB)(((u8 *)"\x33\x35\x35\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x70\x61\x72\x73\x65\x72\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_002A0) != (NULL)));
  return ((A_002A0)->A_00029) - ((A_002A0)->A_0002A);
}

A_00007 (*A_002A4/*parser_at*/(A_00025 (*A_002A2/*parser*/), s64 A_002A3/*relative_index*/))
{
  s64 A_002A5/*absolute_index*/ = 0;

  (A_002EB)(((u8 *)"\x33\x35\x36\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x70\x61\x72\x73\x65\x72\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_002A2) != (NULL)));
  (A_002A5) = (((A_002A2)->A_0002A) + (A_002A3));
  (A_002EB)(((u8 *)"\x33\x35\x36\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x62\x73\x6F\x6C\x75\x74\x65\x5F\x69\x6E\x64\x65\x78\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_002A5) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x35\x36\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x62\x73\x6F\x6C\x75\x74\x65\x5F\x69\x6E\x64\x65\x78\x20\x3C\x20\x70\x61\x72\x73\x65\x72\x2E\x6E\x75\x6D\x5F\x74\x6F\x6B\x65\x6E\x73\x29\x3B"), ((A_002A5) < ((A_002A2)->A_00029)));
  return ((A_002A2)->A_00028) + (A_002A5);
}

A_00007 (*A_002A8/*parser_safe_at*/(A_00025 (*A_002A6/*parser*/), s64 A_002A7/*relative_index*/))
{
  s64 A_002A9/*absolute_index*/ = 0;
  A_00007 (*A_002AA/*result*/) = NULL;

  (A_002EB)(((u8 *)"\x33\x35\x37\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x70\x61\x72\x73\x65\x72\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_002A6) != (NULL)));
  (A_002A9) = (((A_002A6)->A_0002A) + (A_002A7));
  if ((A_002A9) < ((s64)0x0))
  {
    (A_002AA) = ((A_002A6)->A_00026);
  }
  else if ((A_002A9) >= ((A_002A6)->A_00029))
  {
    (A_002AA) = ((A_002A6)->A_00027);
  }
  else
  {
    (A_002AA) = ((A_002A4)((A_002A6), (A_002A7)));
  }
  return A_002AA;
}

u8 (*A_002AC/*c_string_from_node_kind*/(s64 A_002AB/*node_kind*/))
{
  if ((A_002AB) == ((s64)0x0))
  {
    return (u8 *)"\x69\x6E\x76\x61\x6C\x69\x64";
  }
  if ((A_002AB) == ((s64)0x1))
  {
    return (u8 *)"\x73\x74\x61\x74\x65\x6D\x65\x6E\x74\x20\x72\x6F\x6F\x74";
  }
  if ((A_002AB) == ((s64)0x2))
  {
    return (u8 *)"\x73\x74\x61\x74\x65\x6D\x65\x6E\x74\x20\x6C\x69\x73\x74";
  }
  if ((A_002AB) == ((s64)0x3))
  {
    return (u8 *)"\x73\x74\x61\x74\x65\x6D\x65\x6E\x74\x20\x72\x65\x74\x75\x72\x6E";
  }
  if ((A_002AB) == ((s64)0x4))
  {
    return (u8 *)"\x73\x74\x61\x74\x65\x6D\x65\x6E\x74\x20\x62\x72\x65\x61\x6B";
  }
  if ((A_002AB) == ((s64)0x5))
  {
    return (u8 *)"\x73\x74\x61\x74\x65\x6D\x65\x6E\x74\x20\x63\x6F\x6E\x74\x69\x6E\x75\x65";
  }
  if ((A_002AB) == ((s64)0x6))
  {
    return (u8 *)"\x73\x74\x61\x74\x65\x6D\x65\x6E\x74\x20\x77\x68\x69\x6C\x65";
  }
  if ((A_002AB) == ((s64)0x7))
  {
    return (u8 *)"\x73\x74\x61\x74\x65\x6D\x65\x6E\x74\x20\x64\x6F\x2D\x77\x68\x69\x6C\x65";
  }
  if ((A_002AB) == ((s64)0x8))
  {
    return (u8 *)"\x73\x74\x61\x74\x65\x6D\x65\x6E\x74\x20\x69\x66\x2D\x65\x6C\x73\x65";
  }
  if ((A_002AB) == ((s64)0x9))
  {
    return (u8 *)"\x73\x74\x61\x74\x65\x6D\x65\x6E\x74\x20\x63\x5F\x66\x6F\x72";
  }
  if ((A_002AB) == ((s64)0xA))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x6E\x61\x6D\x65";
  }
  if ((A_002AB) == ((s64)0xB))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x6E\x75\x6C\x6C";
  }
  if ((A_002AB) == ((s64)0xC))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x76\x6F\x69\x64";
  }
  if ((A_002AB) == ((s64)0xD))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x75\x36\x34";
  }
  if ((A_002AB) == ((s64)0xE))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x75\x33\x32";
  }
  if ((A_002AB) == ((s64)0xF))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x75\x31\x36";
  }
  if ((A_002AB) == ((s64)0x10))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x75\x38";
  }
  if ((A_002AB) == ((s64)0x11))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x73\x36\x34";
  }
  if ((A_002AB) == ((s64)0x12))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x73\x33\x32";
  }
  if ((A_002AB) == ((s64)0x13))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x73\x31\x36";
  }
  if ((A_002AB) == ((s64)0x14))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x73\x38";
  }
  if ((A_002AB) == ((s64)0x15))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x63\x5F\x64\x62\x67\x70\x6F\x73";
  }
  if ((A_002AB) == ((s64)0x16))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x69\x6E\x74\x65\x67\x65\x72";
  }
  if ((A_002AB) == ((s64)0x17))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x63\x68\x61\x72\x61\x63\x74\x65\x72";
  }
  if ((A_002AB) == ((s64)0x18))
  {
    return (u8 *)"\x70\x72\x69\x6D\x61\x72\x79\x20\x63\x5F\x73\x74\x72\x69\x6E\x67";
  }
  if ((A_002AB) == ((s64)0x19))
  {
    return (u8 *)"\x75\x6E\x61\x72\x79\x20\x2B";
  }
  if ((A_002AB) == ((s64)0x1A))
  {
    return (u8 *)"\x75\x6E\x61\x72\x79\x20\x2D";
  }
  if ((A_002AB) == ((s64)0x1B))
  {
    return (u8 *)"\x75\x6E\x61\x72\x79\x20\x5E";
  }
  if ((A_002AB) == ((s64)0x1C))
  {
    return (u8 *)"\x75\x6E\x61\x72\x79\x20\x2A";
  }
  if ((A_002AB) == ((s64)0x1D))
  {
    return (u8 *)"\x75\x6E\x61\x72\x79\x20\x6E\x6F\x74";
  }
  if ((A_002AB) == ((s64)0x1E))
  {
    return (u8 *)"\x75\x6E\x61\x72\x79\x20\x73\x69\x7A\x65\x5F\x6F\x66";
  }
  if ((A_002AB) == ((s64)0x1F))
  {
    return (u8 *)"\x75\x6E\x61\x72\x79\x20\x61\x6C\x69\x67\x6E\x6D\x65\x6E\x74\x5F\x6F\x66";
  }
  if ((A_002AB) == ((s64)0x20))
  {
    return (u8 *)"\x75\x6E\x61\x72\x79\x20\x2E\x2A";
  }
  if ((A_002AB) == ((s64)0x21))
  {
    return (u8 *)"\x75\x6E\x61\x72\x79\x20\x2E\x26";
  }
  if ((A_002AB) == ((s64)0x22))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x3A";
  }
  if ((A_002AB) == ((s64)0x23))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x2B";
  }
  if ((A_002AB) == ((s64)0x24))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x2D";
  }
  if ((A_002AB) == ((s64)0x25))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x2A";
  }
  if ((A_002AB) == ((s64)0x26))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x2F";
  }
  if ((A_002AB) == ((s64)0x27))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x25";
  }
  if ((A_002AB) == ((s64)0x28))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x26";
  }
  if ((A_002AB) == ((s64)0x29))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x5E";
  }
  if ((A_002AB) == ((s64)0x2A))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x7C";
  }
  if ((A_002AB) == ((s64)0x2B))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x3C\x3C";
  }
  if ((A_002AB) == ((s64)0x2C))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x3E\x3E";
  }
  if ((A_002AB) == ((s64)0x2D))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x2E";
  }
  if ((A_002AB) == ((s64)0x2E))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x3D\x3D";
  }
  if ((A_002AB) == ((s64)0x2F))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x21\x3D";
  }
  if ((A_002AB) == ((s64)0x30))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x3C\x3D";
  }
  if ((A_002AB) == ((s64)0x31))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x3E\x3D";
  }
  if ((A_002AB) == ((s64)0x32))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x3C";
  }
  if ((A_002AB) == ((s64)0x33))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x3E";
  }
  if ((A_002AB) == ((s64)0x34))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x69\x6E\x64\x65\x78";
  }
  if ((A_002AB) == ((s64)0x35))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x61\x6E\x64";
  }
  if ((A_002AB) == ((s64)0x36))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x6F\x72";
  }
  if ((A_002AB) == ((s64)0x37))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x3D";
  }
  if ((A_002AB) == ((s64)0x38))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x2B\x3D";
  }
  if ((A_002AB) == ((s64)0x39))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x2D\x3D";
  }
  if ((A_002AB) == ((s64)0x3A))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x2A\x3D";
  }
  if ((A_002AB) == ((s64)0x3B))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x2F\x3D";
  }
  if ((A_002AB) == ((s64)0x3C))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x25\x3D";
  }
  if ((A_002AB) == ((s64)0x3D))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x26\x3D";
  }
  if ((A_002AB) == ((s64)0x3E))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x5E\x3D";
  }
  if ((A_002AB) == ((s64)0x3F))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x7C\x3D";
  }
  if ((A_002AB) == ((s64)0x40))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x3C\x3C\x3D";
  }
  if ((A_002AB) == ((s64)0x41))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x3E\x3E\x3D";
  }
  if ((A_002AB) == ((s64)0x42))
  {
    return (u8 *)"\x62\x69\x6E\x61\x72\x79\x20\x63\x61\x73\x74";
  }
  if ((A_002AB) == ((s64)0x43))
  {
    return (u8 *)"\x66\x75\x6E\x63\x74\x69\x6F\x6E\x20\x74\x79\x70\x65";
  }
  if ((A_002AB) == ((s64)0x44))
  {
    return (u8 *)"\x66\x75\x6E\x63\x74\x69\x6F\x6E\x20\x63\x61\x6C\x6C";
  }
  if ((A_002AB) == ((s64)0x45))
  {
    return (u8 *)"\x73\x74\x72\x75\x63\x74";
  }
  if ((A_002AB) == ((s64)0x46))
  {
    return (u8 *)"\x63\x5F\x65\x6E\x75\x6D";
  }
  return (u8 *)"\x55\x4E\x4B\x4E\x4F\x57\x4E\x20\x4E\x4F\x44\x45\x20\x4B\x49\x4E\x44\x21\x21\x21\x21\x21\x21\x21\x21\x21\x21\x21\x21\x21\x21\x21\x21\x21\x21\x21\x21\x21\x21";
}

s64 A_002AF/*s64_align*/(s64 A_002AD/*number*/, s64 A_002AE/*alignment*/)
{
  s64 A_002B0/*remainder*/ = 0;

  (A_002EB)(((u8 *)"\x33\x36\x38\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x6C\x69\x67\x6E\x6D\x65\x6E\x74\x20\x3E\x3D\x20\x31\x29\x3B"), ((A_002AE) >= ((s64)0x1)));
  (A_002B0) = ((A_002AD) % (A_002AE));
  if ((A_002B0) == ((s64)0x0))
  {
    return A_002AD;
  }
  return ((A_002AD) + (A_002AE)) - (A_002B0);
}

s64 A_002B3/*s64_max*/(s64 A_002B1/*a*/, s64 A_002B2/*b*/)
{
  if ((A_002B1) > (A_002B2))
  {
    return A_002B1;
  }
  else
  {
    return A_002B2;
  }
}

s64 A_002B6/*s64_min*/(s64 A_002B4/*a*/, s64 A_002B5/*b*/)
{
  if ((A_002B4) < (A_002B5))
  {
    return A_002B4;
  }
  else
  {
    return A_002B5;
  }
}

u64 A_002B9/*u64_max*/(u64 A_002B7/*a*/, u64 A_002B8/*b*/)
{
  if ((A_002B7) > (A_002B8))
  {
    return A_002B7;
  }
  else
  {
    return A_002B8;
  }
}

u64 A_002BC/*u64_min*/(u64 A_002BA/*a*/, u64 A_002BB/*b*/)
{
  if ((A_002BA) < (A_002BB))
  {
    return A_002BA;
  }
  else
  {
    return A_002BB;
  }
}

void A_002C0/*memory_set_every_byte_to_value*/(void (*A_002BD/*a*/), u32 A_002BE/*value*/, s64 A_002BF/*size*/)
{
  (A_002EB)(((u8 *)"\x33\x37\x31\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_002BF) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x37\x32\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x76\x61\x6C\x75\x65\x20\x3C\x3D\x20\x30\x78\x46\x46\x29\x3B"), ((A_002BE) <= ((s64)0xFF)));
  (A_002EB)(((u8 *)"\x33\x37\x32\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3D\x3D\x20\x30\x20\x6F\x72\x20\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (u32)(((A_002BF) == ((s64)0x0)) || ((A_002BD) != (NULL))));
  {
    s64 A_002C1/*i*/ = 0;
    for (; (A_002C1) < (A_002BF); (A_002C1) += ((s64)0x1))
    {
      (((u8 (*))(A_002BD))[A_002C1]) = (A_002BE);
    }
  }
}

void A_002C4/*memory_zero*/(void (*A_002C2/*a*/), s64 A_002C3/*size*/)
{
  (A_002EB)(((u8 *)"\x33\x37\x32\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_002C3) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x37\x33\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3D\x3D\x20\x30\x20\x6F\x72\x20\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (u32)(((A_002C3) == ((s64)0x0)) || ((A_002C2) != (NULL))));
  (A_002C0)((A_002C2), (u32)((s64)0x0), (A_002C3));
}

void A_002C8/*memory_move*/(void (*A_002C5/*dst*/), void (*A_002C6/*src*/), s64 A_002C7/*size*/)
{
  u8 (*A_002C9/*dst_bytes*/) = NULL;
  u8 (*A_002CA/*src_bytes*/) = NULL;

  (A_002EB)(((u8 *)"\x33\x37\x33\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_002C7) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x37\x33\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3D\x3D\x20\x30\x20\x6F\x72\x20\x64\x73\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (u32)(((A_002C7) == ((s64)0x0)) || ((A_002C5) != (NULL))));
  (A_002EB)(((u8 *)"\x33\x37\x33\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3D\x3D\x20\x30\x20\x6F\x72\x20\x73\x72\x63\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (u32)(((A_002C7) == ((s64)0x0)) || ((A_002C6) != (NULL))));
  (A_002C9) = (A_002C5);
  (A_002CA) = (A_002C6);
  if (((s64 )(A_002C5)) <= ((s64 )(A_002C6)))
  {
    {
      s64 A_002CB/*i*/ = 0;
      for (; (A_002CB) < (A_002C7); (A_002CB) += ((s64)0x1))
      {
        ((A_002C9)[A_002CB]) = ((A_002CA)[A_002CB]);
      }
    }
  }
  else
  {
    {
      s64 A_002CC/*i*/ = 0;
      for (; (A_002CC) < (A_002C7); (A_002CC) += ((s64)0x1))
      {
        s64 A_002CD/*ri*/ = 0;

        (A_002CD) = (((A_002C7) - ((s64)0x1)) - (A_002CC));
        ((A_002C9)[A_002CD]) = ((A_002CA)[A_002CD]);
      }
    }
  }
}

u32 A_002D1/*memory_equal*/(void (*A_002CE/*a*/), void (*A_002CF/*b*/), s64 A_002D0/*size*/)
{
  (A_002EB)(((u8 *)"\x33\x37\x36\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_002D0) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x37\x36\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3D\x3D\x20\x30\x20\x6F\x72\x20\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (u32)(((A_002D0) == ((s64)0x0)) || ((A_002CE) != (NULL))));
  (A_002EB)(((u8 *)"\x33\x37\x36\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3D\x3D\x20\x30\x20\x6F\x72\x20\x62\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (u32)(((A_002D0) == ((s64)0x0)) || ((A_002CF) != (NULL))));
  {
    s64 A_002D2/*i*/ = 0;
    for (; (A_002D2) < (A_002D0); (A_002D2) += ((s64)0x1))
    {
      if ((((u8 (*))(A_002CE))[A_002D2]) != (((u8 (*))(A_002CF))[A_002D2]))
      {
        return (s64)0x0;
      }
    }
  }
  return (s64)0x1;
}

void A_002D6/*memory_copy*/(void (*A_002D3/*dst*/), void (*A_002D4/*src*/), s64 A_002D5/*size*/)
{
  (A_002EB)(((u8 *)"\x33\x37\x37\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_002D5) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x37\x37\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3D\x3D\x20\x30\x20\x6F\x72\x20\x64\x73\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (u32)(((A_002D5) == ((s64)0x0)) || ((A_002D3) != (NULL))));
  (A_002EB)(((u8 *)"\x33\x37\x37\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3D\x3D\x20\x30\x20\x6F\x72\x20\x73\x72\x63\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (u32)(((A_002D5) == ((s64)0x0)) || ((A_002D4) != (NULL))));
  {
    s64 A_002D7/*i*/ = 0;
    for (; (A_002D7) < (A_002D5); (A_002D7) += ((s64)0x1))
    {
      (((u8 (*))(A_002D3))[A_002D7]) = (((u8 (*))(A_002D4))[A_002D7]);
    }
  }
}

s64 A_002D9/*cstring_length*/(u8 (*A_002D8/*s*/))
{
  u8 (*A_002DA/*s0*/) = NULL;

  (A_002EB)(((u8 *)"\x33\x37\x38\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_002D8) != (NULL)));
  (A_002DA) = (A_002D8);
  while ((*(A_002D8)) != ((s64)0x0))
  {
    (A_002D8) += ((s64)0x1);
  }
  return (A_002D8) - (A_002DA);
}

u32 A_002DC/*ascii_digit_from_int*/(s64 A_002DB/*number*/)
{
  (A_002EB)(((u8 *)"\x33\x38\x30\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6E\x75\x6D\x62\x65\x72\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_002DB) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x38\x30\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6E\x75\x6D\x62\x65\x72\x20\x3C\x20\x31\x36\x29\x3B"), ((A_002DB) < ((s64)0x10)));
  if ((A_002DB) < ((s64)0xA))
  {
    return (A_002DB) + ((s64)0x30);
  }
  return (((s64)0x41) - ((s64)0xA)) + (A_002DB);
}

s64 A_002DE/*ascii_digit_to_int*/(u32 A_002DD/*c*/)
{
  if ((((s64)0x41) <= (A_002DD)) && ((A_002DD) <= ((s64)0x46)))
  {
    return ((A_002DD) - ((s64)0x41)) + ((s64)0xA);
  }
  if ((((s64)0x61) <= (A_002DD)) && ((A_002DD) <= ((s64)0x66)))
  {
    return ((A_002DD) - ((s64)0x61)) + ((s64)0xA);
  }
  if ((((s64)0x30) <= (A_002DD)) && ((A_002DD) <= ((s64)0x39)))
  {
    return (A_002DD) - ((s64)0x30);
  }
  return (s64)0x64;
}

u64 A_002E0/*ascii_is_space*/(u64 A_002DF/*c*/)
{
  return ((A_002DF) == ((s64)0x20)) || ((A_002DF) == ((s64)0xA));
}

u64 A_002E2/*ascii_is_letter*/(u64 A_002E1/*c*/)
{
  return ((((s64)0x41) <= (A_002E1)) && ((A_002E1) <= ((s64)0x5A))) || ((((s64)0x61) <= (A_002E1)) && ((A_002E1) <= ((s64)0x7A)));
}

u64 A_002E4/*ascii_is_letter_or_digit*/(u64 A_002E3/*c*/)
{
  return (((((s64)0x41) <= (A_002E3)) && ((A_002E3) <= ((s64)0x5A))) || ((((s64)0x61) <= (A_002E3)) && ((A_002E3) <= ((s64)0x7A)))) || ((((s64)0x30) <= (A_002E3)) && ((A_002E3) <= ((s64)0x39)));
}

u64 A_002E6/*ascii_is_decimal_digit*/(u64 A_002E5/*c*/)
{
  return (((s64)0x30) <= (A_002E5)) && ((A_002E5) <= ((s64)0x39));
}

u64 A_002E8/*ascii_is_uppercase_hexadecimal_digit*/(u64 A_002E7/*c*/)
{
  return ((((s64)0x41) <= (A_002E7)) && ((A_002E7) <= ((s64)0x46))) || ((((s64)0x30) <= (A_002E7)) && ((A_002E7) <= ((s64)0x39)));
}

void A_002EB/*debug_assert*/(u8 (*A_002E9/*dbgpos*/), u32 A_002EA/*_true*/)
{
  if (!(A_002EA))
  {
    (A_00344)(((u8 *)"\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x20\x46\x41\x49\x4C\x45\x44\x0A"), (A_002E9));
  }
}

void A_002EE/*resource_assert*/(u8 (*A_002EC/*dbgpos*/), u32 A_002ED/*_true*/)
{
  if (!(A_002ED))
  {
    (A_00344)(((u8 *)"\x72\x65\x73\x6F\x75\x72\x63\x65\x5F\x61\x73\x73\x65\x72\x74\x20\x46\x41\x49\x4C\x45\x44\x0A"), (A_002EC));
  }
}

void A_002F1/*error_assert*/(u8 (*A_002EF/*dbgpos*/), u32 A_002F0/*_true*/)
{
  if (!(A_002F0))
  {
    (A_00344)(((u8 *)"\x65\x72\x72\x6F\x72\x5F\x61\x73\x73\x65\x72\x74\x20\x46\x41\x49\x4C\x45\x44\x0A"), (A_002EF));
  }
}

s64 A_002F5/*arena_print_bytes*/(A_00001 (*A_002F2/*arena*/), s64 A_002F3/*size*/, void (*A_002F4/*data*/))
{
  (A_002EB)(((u8 *)"\x33\x38\x37\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_002F2) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x38\x37\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_002F2)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x38\x37\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_002F2)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x38\x37\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_002F2)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x38\x37\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_002F2)->A_00005) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x38\x37\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_002F3) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x38\x38\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x64\x61\x74\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x20\x6F\x72\x20\x73\x69\x7A\x65\x20\x3D\x3D\x20\x30\x29\x3B"), (u32)(((A_002F4) != (NULL)) || ((A_002F3) == ((s64)0x0))));
  (A_00334)((A_002F2), (A_002F3), (A_002F4));
  return A_002F3;
}

s64 A_002F8/*arena_print_cstring*/(A_00001 (*A_002F6/*arena*/), u8 (*A_002F7/*cstring*/))
{
  (A_002EB)(((u8 *)"\x33\x38\x38\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_002F6) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x38\x39\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_002F6)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x38\x39\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_002F6)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x38\x39\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_002F6)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x38\x39\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_002F6)->A_00005) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x38\x39\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x63\x73\x74\x72\x69\x6E\x67\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_002F7) != (NULL)));
  return (A_002F5)((A_002F6), ((A_002D9)((A_002F7))), (A_002F7));
}

s64 A_002FC/*arena_print_row*/(A_00001 (*A_002F9/*arena*/), s64 A_002FA/*size*/, u32 A_002FB/*ch*/)
{
  void (*A_002FD/*bytes*/) = NULL;

  (A_002EB)(((u8 *)"\x33\x39\x30\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_002F9) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x39\x30\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_002F9)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x39\x30\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_002F9)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x39\x30\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_002F9)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x39\x30\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_002F9)->A_00005) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x39\x30\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_002FA) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x39\x30\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x63\x68\x20\x3C\x3D\x20\x30\x78\x46\x46\x29\x3B"), ((A_002FB) <= ((s64)0xFF)));
  (A_002FD) = ((A_0032B)((A_002F9), (A_002FA)));
  (A_002C0)((A_002FD), (A_002FB), (A_002FA));
  return A_002FA;
}

s64 A_00302/*arena_print_u64*/(A_00001 (*A_002FE/*arena*/), u64 A_002FF/*number*/, u64 A_00300/*base*/, s64 A_00301/*min_length*/)
{
  s64 A_00303/*size*/ = 0;
  s64 A_00304/*ndigits*/ = 0;
  u64 A_00305/*copy*/ = 0;
  u8 (*A_00306/*chars*/) = NULL;

  (A_002EB)(((u8 *)"\x33\x39\x31\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_002FE) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x39\x31\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_002FE)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x39\x32\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_002FE)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x39\x32\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_002FE)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x39\x32\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_002FE)->A_00005) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x39\x32\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x62\x61\x73\x65\x20\x3E\x3D\x20\x32\x29\x3B"), ((A_00300) >= ((s64)0x2)));
  (A_002EB)(((u8 *)"\x33\x39\x32\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x62\x61\x73\x65\x20\x3C\x3D\x20\x31\x36\x29\x3B"), ((A_00300) <= ((s64)0x10)));
  (A_002EB)(((u8 *)"\x33\x39\x32\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6D\x69\x6E\x5F\x6C\x65\x6E\x67\x74\x68\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_00301) >= ((s64)0x0)));
  (A_00304) = ((s64)0x1);
  (A_00305) = ((A_002FF) / (A_00300));
  while ((A_00305) > ((s64)0x0))
  {
    (A_00304) += ((s64)0x1);
    (A_00305) /= (A_00300);
  }
  if ((A_00304) < (A_00301))
  {
    (A_002FC)((A_002FE), ((A_00301) - (A_00304)), (u32)((s64)0x30));
    (A_00303) = (A_00301);
  }
  else
  {
    (A_00303) = (A_00304);
  }
  (A_00306) = ((A_0032B)((A_002FE), (A_00304)));
  {
    s64 A_00307/*i*/ = 0;
    for (; (A_00307) < (A_00304); (A_00307) += ((s64)0x1))
    {
      s64 A_00308/*ri*/ = 0;

      (A_00308) = (((A_00304) - ((s64)0x1)) - (A_00307));
      ((A_00306)[A_00308]) = ((A_002DC)(((A_002FF) % (A_00300))));
      (A_002FF) /= (A_00300);
    }
  }
  return A_00303;
}

s64 A_0030D/*arena_print_s64*/(A_00001 (*A_00309/*arena*/), s64 A_0030A/*number*/, u64 A_0030B/*base*/, s64 A_0030C/*min_length*/)
{
  s64 A_0030E/*result*/ = 0;

  (A_002EB)(((u8 *)"\x33\x39\x36\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00309) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x39\x36\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00309)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x39\x36\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00309)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x39\x36\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00309)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x39\x36\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00309)->A_00005) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x39\x36\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x62\x61\x73\x65\x20\x3E\x3D\x20\x32\x29\x3B"), ((A_0030B) >= ((s64)0x2)));
  (A_002EB)(((u8 *)"\x33\x39\x36\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x62\x61\x73\x65\x20\x3C\x3D\x20\x31\x36\x29\x3B"), ((A_0030B) <= ((s64)0x10)));
  (A_002EB)(((u8 *)"\x33\x39\x37\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6D\x69\x6E\x5F\x6C\x65\x6E\x67\x74\x68\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_0030C) >= ((s64)0x0)));
  if ((A_0030A) < ((s64)0x0))
  {
    (A_0030E) += ((s64)0x1);
    (A_0030A) *= (-((s64)0x1));
    (A_0030C) = ((A_002B3)(((s64)0x0), ((A_0030C) - ((s64)0x1))));
  }
  (A_0030E) += ((A_00302)((A_00309), (A_0030A), (A_0030B), (A_0030C)));
  return A_0030E;
}

s64 A_00311/*arena_print_cyechar*/(A_00001 (*A_0030F/*arena*/), u64 A_00310/*cyechar*/)
{
  s64 A_00312/*max_length*/ = 0;
  u8 (*A_00314/*chars*/) = NULL;

  (A_002EB)(((u8 *)"\x33\x39\x38\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0030F) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x39\x38\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_0030F)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x33\x39\x39\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_0030F)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x39\x39\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_0030F)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x33\x39\x39\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_0030F)->A_00005) >= ((s64)0x0)));
  {
    s64 A_00313/*i*/ = 0;
    for (; (A_00313) < ((s64)0x8); (A_00313) += ((s64)0x1))
    {
      if ((((A_00310) >> ((A_00313) * ((s64)0x8))) & ((s64)0xFF)) != ((s64)0x0))
      {
        (A_00312) = ((A_00313) + ((s64)0x1));
      }
    }
  }
  (A_00314) = ((A_0032B)((A_0030F), (A_00312)));
  {
    s64 A_00315/*i*/ = 0;
    for (; (A_00315) < (A_00312); (A_00315) += ((s64)0x1))
    {
      ((A_00314)[A_00315]) = (((A_00310) >> ((A_00315) * ((s64)0x8))) & ((s64)0xFF));
    }
  }
  return A_00312;
}

A_00001 (*A_00317/*arena_create*/(s64 A_00316/*min_reserved*/))
{
  s64 A_00318/*one_page*/ = 0;
  s64 A_00319/*reserved*/ = 0;
  s64 A_0031A/*commited*/ = 0;
  s64 A_0031B/*true_reserved*/ = 0;
  s64 A_0031C/*true_commited*/ = 0;
  void (*A_0031D/*p_0*/) = NULL;
  u32 A_0031E/*err*/ = 0;
  A_00001 (*A_0031F/*arena*/) = NULL;

  (A_002EB)(((u8 *)"\x34\x30\x31\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6D\x69\x6E\x5F\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_00316) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x30\x31\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6D\x69\x6E\x5F\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3C\x20\x31\x2E\x63\x61\x73\x74\x28\x73\x36\x34\x29\x20\x3C\x3C\x20\x34\x30\x29\x3B\x20\x2F\x2F\x20\x54\x4F\x44\x4F\x3A\x20\x6E\x6F\x20\x63\x61\x73\x74"), ((A_00316) < (((s64 )((s64)0x1)) << ((s64)0x28))));
  (A_00318) = ((s64)0x1000);
  (A_00319) = (A_00318);
  (A_0031A) = (A_00318);
  while ((A_00319) < (A_00316))
  {
    (A_00319) *= ((s64)0x2);
  }
  (A_0031B) = ((A_00318) + (A_00319));
  (A_0031C) = ((A_00318) + (A_0031A));
  (A_0031D) = ((A_0033F)((A_0031B)));
  (A_002EE)(((u8 *)"\x34\x30\x33\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x72\x65\x73\x6F\x75\x72\x63\x65\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x70\x5F\x30\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0031D) != (NULL)));
  (A_0031E) = ((A_0033C)((A_0031C), (A_0031D)));
  (A_002EE)(((u8 *)"\x34\x30\x33\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x72\x65\x73\x6F\x75\x72\x63\x65\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x65\x72\x72\x20\x3D\x3D\x20\x30\x29\x3B"), ((A_0031E) == ((s64)0x0)));
  (A_0031F) = (A_0031D);
  ((A_0031F)->A_00002) = (((u8 (*))(A_0031D)) + (A_00318));
  ((A_0031F)->A_00005) = (A_00319);
  ((A_0031F)->A_00004) = (A_0031A);
  ((A_0031F)->A_00003) = ((s64)0x0);
  (A_002EB)(((u8 *)"\x34\x30\x34\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0031F) != (NULL)));
  return A_0031F;
}

void (*A_00321/*arena_get_top*/(A_00001 (*A_00320/*arena*/)))
{
  (A_002EB)(((u8 *)"\x34\x30\x35\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00320) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x30\x35\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00320)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x30\x35\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00320)->A_00003) >= ((s64)0x0)));
  return ((A_00320)->A_00002) + ((A_00320)->A_00003);
}

void (*A_00324/*arena_push_uninited*/(A_00001 (*A_00322/*arena*/), s64 A_00323/*size*/))
{
  void (*A_00325/*result*/) = NULL;

  (A_002EB)(((u8 *)"\x34\x30\x35\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00322) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x30\x35\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00322)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x30\x36\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00322)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x30\x36\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00322)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x30\x36\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00322)->A_00005) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x30\x36\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_00323) >= ((s64)0x0)));
  (A_00325) = ((A_00321)((A_00322)));
  ((A_00322)->A_00003) += (A_00323);
  while (((A_00322)->A_00004) < ((A_00322)->A_00003))
  {
    s64 A_00326/*commited*/ = 0;
    void (*A_00327/*new_half*/) = NULL;
    u32 A_00328/*err*/ = 0;

    (A_00326) = ((A_00322)->A_00004);
    (A_00327) = (((A_00322)->A_00002) + (A_00326));
    ((A_00322)->A_00004) *= ((s64)0x2);
    (A_002EE)(((u8 *)"\x34\x30\x37\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x72\x65\x73\x6F\x75\x72\x63\x65\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3C\x3D\x20\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x29\x3B"), (((A_00322)->A_00004) <= ((A_00322)->A_00005)));
    (A_00328) = ((A_0033C)((A_00326), (A_00327)));
    (A_002EE)(((u8 *)"\x34\x30\x38\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x20\x20\x72\x65\x73\x6F\x75\x72\x63\x65\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x65\x72\x72\x20\x3D\x3D\x20\x30\x29\x3B"), ((A_00328) == ((s64)0x0)));
  }
  (A_002EB)(((u8 *)"\x34\x30\x38\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00325) != (NULL)));
  return A_00325;
}

void (*A_0032B/*arena_push*/(A_00001 (*A_00329/*arena*/), s64 A_0032A/*size*/))
{
  void (*A_0032C/*result*/) = NULL;

  (A_002EB)(((u8 *)"\x34\x30\x39\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00329) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x30\x39\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00329)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x30\x39\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00329)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x30\x39\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00329)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x30\x39\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00329)->A_00005) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x30\x39\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_0032A) >= ((s64)0x0)));
  (A_0032C) = ((A_00324)((A_00329), (A_0032A)));
  (A_002C4)((A_0032C), (A_0032A));
  (A_002EB)(((u8 *)"\x34\x31\x30\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0032C) != (NULL)));
  return A_0032C;
}

void A_0032F/*arena_push_aligner*/(A_00001 (*A_0032D/*arena*/), s64 A_0032E/*alignment*/)
{
  s64 A_00330/*remainder*/ = 0;

  (A_002EB)(((u8 *)"\x34\x31\x30\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0032D) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x31\x30\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_0032D)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x31\x30\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_0032D)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x31\x30\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_0032D)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x31\x31\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_0032D)->A_00005) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x31\x31\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x6C\x69\x67\x6E\x6D\x65\x6E\x74\x20\x3E\x3D\x20\x31\x29\x3B"), ((A_0032E) >= ((s64)0x1)));
  (A_00330) = (((A_0032D)->A_00003) % (A_0032E));
  if ((A_00330) != ((s64)0x0))
  {
    (A_0032B)((A_0032D), ((A_0032E) - (A_00330)));
  }
}

void (*A_00334/*arena_push_copy*/(A_00001 (*A_00331/*arena*/), s64 A_00332/*size*/, void (*A_00333/*data*/)))
{
  void (*A_00335/*result*/) = NULL;

  (A_002EB)(((u8 *)"\x34\x31\x32\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00331) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x31\x32\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00331)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x31\x32\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00331)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x31\x32\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00331)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x31\x32\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00331)->A_00005) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x31\x32\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_00332) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x31\x32\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x64\x61\x74\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x20\x6F\x72\x20\x73\x69\x7A\x65\x20\x3D\x3D\x20\x30\x29\x3B"), (u32)(((A_00333) != (NULL)) || ((A_00332) == ((s64)0x0))));
  (A_00335) = ((A_00324)((A_00331), (A_00332)));
  (A_002D6)((A_00335), (A_00333), (A_00332));
  (A_002EB)(((u8 *)"\x34\x31\x33\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00335) != (NULL)));
  return A_00335;
}

void A_00338/*arena_pop_to_pointer*/(A_00001 (*A_00336/*arena*/), void (*A_00337/*pointer*/))
{
  s64 A_00339/*new_pushed*/ = 0;

  (A_002EB)(((u8 *)"\x34\x31\x33\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00336) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x31\x33\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00336)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x31\x33\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00336)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x31\x34\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00336)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x31\x34\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00336)->A_00005) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x31\x34\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x70\x6F\x69\x6E\x74\x65\x72\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00337) != (NULL)));
  (A_00339) = (((u8 (*))(A_00337)) - ((A_00336)->A_00002));
  (A_002EB)(((u8 *)"\x34\x31\x34\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6E\x65\x77\x5F\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_00339) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x31\x34\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6E\x65\x77\x5F\x70\x75\x73\x68\x65\x64\x20\x3C\x3D\x20\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x29\x3B"), ((A_00339) <= ((A_00336)->A_00003)));
  ((A_00336)->A_00003) = (A_00339);
}

u32 A_0033C/*system_memory_commit*/(s64 A_0033A/*size*/, void (*A_0033B/*base*/))
{
  void (*A_0033D/*pointer*/) = NULL;

  (A_0033D) = ((VirtualAlloc)((A_0033B), (A_0033A), (u32)((s64)0x1000), (u32)((s64)0x4)));
  return (A_0033D) == (NULL);
}

void (*A_0033F/*system_memory_reserve*/(s64 A_0033E/*size*/))
{
  void (*A_00340/*result*/) = NULL;

  (A_002EB)(((u8 *)"\x34\x31\x37\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_0033E) >= ((s64)0x0)));
  (A_00340) = ((VirtualAlloc)((NULL), (A_0033E), (u32)((s64)0x2000), (u32)((s64)0x4)));
  return A_00340;
}

void (*A_00341/*get_w_stderr*/(void))
{
  return (GetStdHandle)((s32)(-((s64)0xC)));
}

void A_00344/*say_and_die*/(u8 (*A_00342/*msg*/), u8 (*A_00343/*dbgpos*/))
{
  void (*A_00345/*f*/) = NULL;

  (A_00345) = ((A_00341)());
  (WriteFile)((A_00345), (A_00342), (u32)((A_002D9)((A_00342))), (NULL), (NULL));
  (WriteFile)((A_00345), (A_00343), (u32)((A_002D9)((A_00343))), (NULL), (NULL));
  (WriteFile)((A_00345), ((u8 *)"\x0A"), (u32)((s64)0x1), (NULL), (NULL));
  (ExitProcess)((u32)((s64)0x1));
}

u8 (*(*A_00348/*command_get_arguments*/(A_00001 (*A_00346/*result_arena*/), A_00001 (*A_00347/*temp_arena*/))))
{
  s64 A_00349/*num_arguments*/ = 0;
  u8 (*A_0034A/*command_line*/) = NULL;
  u8 (*A_0034B/*cp*/) = NULL;
  u8 (*A_0034C/*temp_arena_beg*/) = NULL;
  u8 (*(*A_00351/*result*/)) = NULL;

  (A_002EB)(((u8 *)"\x34\x32\x30\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x5F\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00346) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x32\x30\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x5F\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00346)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x32\x30\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x5F\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00346)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x32\x30\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x5F\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00346)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x32\x30\x37\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x5F\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00346)->A_00005) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x32\x30\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x74\x65\x6D\x70\x5F\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00347) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x32\x30\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x74\x65\x6D\x70\x5F\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00347)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x32\x31\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x74\x65\x6D\x70\x5F\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00347)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x32\x31\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x74\x65\x6D\x70\x5F\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00347)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x32\x31\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x74\x65\x6D\x70\x5F\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00347)->A_00005) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x32\x31\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x5F\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x74\x65\x6D\x70\x5F\x61\x72\x65\x6E\x61\x29\x3B"), ((A_00346) != (A_00347)));
  (A_0034A) = ((GetCommandLineA)());
  (A_0034B) = (A_0034A);
  (A_0034C) = ((A_00321)((A_00347)));
  while ((*(A_0034B)) != ((s64)0x0))
  {
    u8 (*A_0034D/*argument_beg*/) = NULL;
    u8 (*A_0034E/*argument_end*/) = NULL;
    s64 A_0034F/*argument_size*/ = 0;
    u8 (*A_00350/*argument_value*/) = NULL;

    while ((*(A_0034B)) == ((s64)0x20))
    {
      (A_0034B) += ((s64)0x1);
    }
    (A_0034D) = (A_0034B);
    while (((*(A_0034B)) != ((s64)0x20)) && ((*(A_0034B)) != ((s64)0x0)))
    {
      (A_0034B) += ((s64)0x1);
    }
    (A_0034E) = (A_0034B);
    (A_0034F) = ((A_0034E) - (A_0034D));
    (A_00350) = ((A_00334)((A_00346), (A_0034F), (A_0034D)));
    (A_0032B)((A_00346), ((s64)0x1));
    (A_00334)((A_00347), ((s64)0x8), (&(A_00350)));
    (A_00349) += ((s64)0x1);
  }
  (A_0032F)((A_00346), ((s64)0x8));
  (A_00351) = ((A_00334)((A_00346), ((A_00349) * ((s64)0x8)), (A_0034C)));
  (A_0032B)((A_00346), ((s64)0x8));
  (A_00338)((A_00347), (A_0034C));
  return (A_00351) + ((s64)0x1);
}

void (*A_00354/*file_read_all_bytes*/(u8 (*A_00352/*cpath*/), A_00001 (*A_00353/*result_arena*/)))
{
  void (*A_00355/*result*/) = NULL;
  void (*A_00356/*file_handle*/) = NULL;

  (A_002EB)(((u8 *)"\x34\x32\x35\x38\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x63\x70\x61\x74\x68\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00352) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x32\x35\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x5F\x61\x72\x65\x6E\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_00353) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x32\x36\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x5F\x61\x72\x65\x6E\x61\x2E\x61\x74\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), (((A_00353)->A_00002) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x32\x36\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x5F\x61\x72\x65\x6E\x61\x2E\x70\x75\x73\x68\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00353)->A_00003) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x32\x36\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x5F\x61\x72\x65\x6E\x61\x2E\x63\x6F\x6D\x6D\x69\x74\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00353)->A_00004) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x32\x36\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x72\x65\x73\x75\x6C\x74\x5F\x61\x72\x65\x6E\x61\x2E\x72\x65\x73\x65\x72\x76\x65\x64\x20\x3E\x3D\x20\x30\x29\x3B"), (((A_00353)->A_00005) >= ((s64)0x0)));
  (A_00356) = ((CreateFileA)((A_00352), (u32)((s64)0x80000000), (u32)((s64)0x0), (NULL), (u32)((s64)0x3), (u32)((s64)0x80), (NULL)));
  if ((A_00356) != ((void (*))(~((u64 )((s64)0x0)))))
  {
    u32 A_00357/*file_size*/ = 0;
    s64 A_00358/*valid_file_size*/ = 0;
    u8 (*A_00359/*file_content*/) = NULL;
    s32 A_0035A/*ok_0*/ = 0;
    s32 A_0035B/*ok_1*/ = 0;
    s32 A_0035C/*ok_2*/ = 0;
    u32 A_0035D/*file_size_out*/ = 0;

    (A_00357) = ((GetFileSize)((A_00356), (NULL)));
    if ((A_00357) != ((s64)0xFFFFFFFF))
    {
      (A_00358) = (A_00357);
    }
    (A_00359) = ((A_0032B)((A_00353), (A_00358)));
    (A_0035A) = ((ReadFile)((A_00356), (A_00359), (u32)(A_00358), (&(A_0035D)), (NULL)));
    (A_0035B) = ((A_00358) == (A_0035D));
    (A_0035C) = ((CloseHandle)((A_00356)));
    if (((A_0035A) && (A_0035B)) && (A_0035C))
    {
      (A_00355) = (A_00359);
    }
    else
    {
      (A_00338)((A_00353), (A_00359));
    }
  }
  return A_00355;
}

u32 A_00361/*file_write_all_bytes*/(u8 (*A_0035E/*cpath*/), s64 A_0035F/*size*/, void (*A_00360/*data*/))
{
  u32 A_00362/*result*/ = 0;
  void (*A_00363/*file_handle*/) = NULL;

  (A_002EB)(((u8 *)"\x34\x32\x39\x39\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x63\x70\x61\x74\x68\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0035E) != (NULL)));
  (A_002EB)(((u8 *)"\x34\x33\x30\x30\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_0035F) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x33\x30\x31\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3C\x20\x30\x78\x31\x30\x30\x30\x30\x30\x30\x30\x29\x3B"), ((A_0035F) < ((s64)0x10000000)));
  (A_002EB)(((u8 *)"\x34\x33\x30\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x64\x61\x74\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x20\x6F\x72\x20\x73\x69\x7A\x65\x20\x3D\x3D\x20\x30\x29\x3B"), (u32)(((A_00360) != (NULL)) || ((A_0035F) == ((s64)0x0))));
  (A_00363) = ((CreateFileA)((A_0035E), (u32)((s64)0x40000000), (u32)((s64)0x0), (NULL), (u32)((s64)0x2), (u32)((s64)0x80), (NULL)));
  if ((A_00363) != ((void (*))(~((u64 )((s64)0x0)))))
  {
    s32 A_00364/*ok_0*/ = 0;
    s32 A_00365/*ok_1*/ = 0;

    (A_00364) = ((WriteFile)((A_00363), (A_00360), (u32)(A_0035F), (NULL), (NULL)));
    (A_00365) = ((CloseHandle)((A_00363)));
    (A_00362) = ((A_00364) && (A_00365));
  }
  return A_00362;
}

void A_00367/*process_exit*/(u32 A_00366/*status*/)
{
  (ExitProcess)((A_00366));
}

void A_0036A/*console_error_print_bytes*/(s64 A_00368/*size*/, void (*A_00369/*data*/))
{
  (A_002EB)(((u8 *)"\x34\x33\x33\x34\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x73\x69\x7A\x65\x20\x3E\x3D\x20\x30\x29\x3B"), ((A_00368) >= ((s64)0x0)));
  (A_002EB)(((u8 *)"\x34\x33\x33\x35\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x64\x61\x74\x61\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x20\x6F\x72\x20\x73\x69\x7A\x65\x20\x3D\x3D\x20\x30\x29\x3B"), (u32)(((A_00369) != (NULL)) || ((A_00368) == ((s64)0x0))));
  (WriteFile)((A_00371), (A_00369), (u32)(A_00368), (NULL), (NULL));
}

void A_0036C/*console_error_print_cstring*/(u8 (*A_0036B/*cstring*/))
{
  (A_002EB)(((u8 *)"\x34\x33\x34\x32\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x64\x65\x62\x75\x67\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x63\x73\x74\x72\x69\x6E\x67\x20\x21\x3D\x20\x6E\x75\x6C\x6C\x29\x3B"), ((A_0036B) != (NULL)));
  (A_0036A)(((A_002D9)((A_0036B))), (A_0036B));
}

void A_0036D/*console_init*/(void)
{
  u32 A_0036E/*prev_mode*/ = 0;
  s32 A_0036F/*ok_0*/ = 0;
  s32 A_00370/*ok_1*/ = 0;

  (A_00371) = ((A_00341)());
  (A_0036F) = ((GetConsoleMode)((A_00371), (&(A_0036E))));
  (A_002EE)(((u8 *)"\x34\x33\x35\x33\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x72\x65\x73\x6F\x75\x72\x63\x65\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6F\x6B\x5F\x30\x29\x3B"), (A_0036F));
  (A_00370) = ((SetConsoleMode)((A_00371), (u32)((A_0036E) | ((s64)0x4))));
  (A_002EE)(((u8 *)"\x34\x33\x35\x36\x3A\x20\x63\x5F\x64\x62\x67\x70\x6F\x73\x3A\x20\x20\x20\x72\x65\x73\x6F\x75\x72\x63\x65\x5F\x61\x73\x73\x65\x72\x74\x28\x63\x5F\x64\x62\x67\x70\x6F\x73\x2C\x20\x6F\x6B\x5F\x31\x29\x3B"), (A_00370));
}

void _start(void)
{
  extern void ExitProcess(u32 status);
  
  (void) A_002B6;
  (void) A_002B9;
  (void) A_002BC;
  (void) A_002C8;
  (void) A_00311;
  
  A_00103();
  ExitProcess(0);
}



