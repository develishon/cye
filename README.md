
# Cye

Cye is a general-purpose imperative procedural programming language,
replicating the semantics of C and getting rid of its backward compatibility.

In other words, Cye is the new C but there is nothing new in it.

## The Current Status

Prototyping.

The language definition is incomplete at the moment. The compiler is full of temporary decisions.
Most of the implementation is going to change in a backwards incompatible way.
It will be foolish of someone to use this language in a serious project.

## The Goal

The goal of this project is to make a programming language that is semantically equivalent to C,
and to leave behind all the inconveniences caused by the limitations of the 1970s computer systems.
The inconveniences include but not limited by:

1. Forward declaration;
2. Header files;
3. Context-depended parsing;
4. Null-terminated strings;
5. Undefined size and signess of integer types;
6. Incremental builds;
7. Textual preprocessing;
8. The standard library being one example of a horrible API design;
9. The operator precedence being unmemorizable.

## NOT The Goal

Replicating C syntax. Implementing features beyond ones that C already offers.

## Contribution

Despite it being a public repo, this is a personal project of the author with the author being the main customer
of the software. All contribution attempts are going to be met with a LOT of skepticism and mistrust.

## License

The MIT License.


