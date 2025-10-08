# Libft

[![Libft Banner](https://img.shields.io/badge/42-Project-blue?style=flat&logo=42&logoColor=white)](https://www.42.fr/)
[![Language](https://img.shields.io/badge/Language-C-blueviolet?style=flat)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norm](https://img.shields.io/badge/Norm-Compliant-green?style=flat)](https://norminette.42.fr/)

Your very first own library. This project involves coding a C library that will include numerous general-purpose functions for your programs. It aims to help you understand standard C functions by reimplementing them, creating a valuable tool for future assignments in the 42 cursus.

## Table of Contents

- [Introduction](#introduction)
- [Common Instructions](#common-instructions)
- [AI Guidelines](#ai-guidelines)
- [Mandatory Part](#mandatory-part)
  - [Technical Considerations](#technical-considerations)
  - [Part 1: Libc Functions](#part-1-libc-functions)
  - [Part 2: Additional Functions](#part-2-additional-functions)
- [Bonus Part](#bonus-part)
- [Compilation](#compilation)
- [Usage](#usage)
- [Submission](#submission)
- [License](#license)

## Introduction

C programming can be quite tedious without access to the highly useful standard functions. This project aims to help you understand how these functions work by implementing them yourself and learning to use them effectively. You will create your own library, which will be valuable for your future C school assignments.

Take the time to expand your libft throughout the year. However, when working on a new project, always check that the functions used in your library comply with the project guidelines.

## Common Instructions

- Your project must be written in C.
- Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check, and you will receive a 0 if there is a norm error.
- Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc.) except for undefined behavior. If this occurs, your project will be considered non-functional and will receive a 0 during the evaluation.
- All heap-allocated memory must be properly freed when necessary. Memory leaks will not be tolerated.
- If the subject requires it, you must submit a Makefile that compiles your source files to the required output with the flags -Wall, -Wextra, and -Werror, using cc. Additionally, your Makefile must not perform unnecessary relinking.
- Your Makefile must contain at least the rules $(NAME), all, clean, fclean and re.
- To submit bonuses for your project, you must include a bonus rule in your Makefile, which will add all the various headers, libraries, or functions that are not allowed in the main part of the project. Bonuses must be placed in _bonus.{c/h} files, unless the subject specifies otherwise. The evaluation of mandatory and bonus parts is conducted separately.
- If your project allows you to use your libft, you must copy its sources and its associated Makefile into a libft folder. Your project’s Makefile must compile the library by using its Makefile, then compile the project.
- We encourage you to create test programs for your project, even though this work does not need to be submitted and will not be graded. It will give you an opportunity to easily test your work and your peers’ work. You will find these tests especially useful during your defence.
- Submit your work to the assigned Git repository. Only the work in the Git repository will be graded. If Deepthought is assigned to grade your work, it will occur after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.

## AI Guidelines

Build strong foundations without shortcuts. Develop tech and power skills through challenge, repetition, and peer-learning.

- You should apply reasoning to your assigned tasks, especially before turning to AI.
- You should not ask for direct answers to the AI.
- You should learn about 42 global approach on AI.

Outcomes: Proper tech foundations; understand AI risks in this phase.

Comments and Example:
- Yes, we know AI exists — and yes, it can solve your projects. But you’re here to learn, not to prove that AI has learned. Don’t waste your time (or ours) just to demonstrate that AI can solve the given problem.
- Learning at 42 isn’t about knowing the answer — it’s about developing the ability to find one. AI gives you the answer directly, but that prevents you from building your own reasoning. And reasoning takes time, effort, and involves failure. The path to success is not supposed to be easy.
- Keep in mind that during exams, AI is not available — no internet, no smartphones, etc. You’ll quickly realise if you’ve relied too heavily on AI in your learning process.
- Peer learning exposes you to different ideas and approaches, improving your interpersonal skills and your ability to think divergently. That’s far more valuable than just chatting with a bot. So don’t be shy — talk, ask questions, and learn together!
- Good practice: I’m stuck on a new concept. I ask someone nearby how they approached it. We talk for 10 minutes — and suddenly it clicks. I get it.
- Bad practice: I secretly use AI, copy some code that looks right. During peer evaluation, I can’t explain anything. I fail. During the exam — no AI — I’m stuck again. I fail.

## Mandatory Part

Program: `libft.a`  
Files: `Makefile`, `libft.h`, `ft_*.c`  
Makefile: `NAME`, `all`, `clean`, `fclean`, `re`  
External Function: Detailed below  
Libft authorized: n/a  
Description: Create your own library: a collection of functions that will serve as a useful tool throughout your cursus.

### Technical Considerations

- Declaring global variables is strictly forbidden.
- If you need helper functions to break down a more complex function, define them as static functions to restrict their scope to the appropriate file.
- All files must be placed at the root of your repository.
- Submitting unused files is not allowed.
- Every .c file must compile with the following flags: -Wall -Wextra -Werror.
- You must use the ar command to create your library. The use of libtool is strictly forbidden.
- Your libft.a must be created at the root of your repository.

### Part 1: Libc Functions

To begin, you must reimplement a set of functions from the libc. Your version will have the same prototypes and behaviors as the originals, adhering strictly to their definitions in the man page. The only difference will be their names, as they must start with the ‘ft_’ prefix. For example, strlen becomes ft_strlen.

Some of the function prototypes you need to reimplement use the ‘restrict’ qualifier. This keyword is part of the C99 standard. Therefore, it is forbidden to include it in your own prototypes or to compile your code with the -std=c99 flag.

The following functions must be rewritten without relying on external functions:

- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_strlen`
- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_toupper`
- `ft_tolower`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_memchr`
- `ft_memcmp`
- `ft_strnstr`
- `ft_atoi`

To implement the two following functions, you will use malloc():

- `ft_calloc` (Follows rule: If nmemb or size is 0, then calloc() returns a unique pointer value that can be successfully passed to free())
- `ft_strdup`

Some functions that you must reimplement, such as strlcpy, strlcat, and bzero, are not included by default in the GNU C Library (glibc). To test them against the system standard, you may need to include <bsd/string.h> and compile with the -lbsd flag. This behaviour is specific to glibc systems. If you are curious, take the opportunity to explore the differences between glc and BSD libc.

### Part 2: Additional Functions

| Function      | Prototype                                    | Description                                                                 |
|---------------|----------------------------------------------|-----------------------------------------------------------------------------|
| `ft_substr`   | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Allocates memory and returns a substring from `s` starting at `start` with max length
