/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** store word into array
*/

// #include<stdlib.h>

// int my_strlen(char const *str);

// int check_alpha(char c)
// {
//     if (c >= '0' && c <= '9')
//         return 1;
//     if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
//         return 1;
//     return 0;
// }

// char **store_words(char const *str, char **str_rtn)
// {
//     int i = 0;
//     int nb_wrd = 0;
//     int chr_wrd = 0;
//     while (str[i] != '\0') {
//         if (check_alpha(str[i]) == 1) {
//             str_rtn[nb_wrd][chr_wrd] = str[i];
//             chr_wrd++;
//         } else if (chr_wrd > 0) {
//             str_rtn[nb_wrd][chr_wrd] = '\0';
//             nb_wrd++;
//             chr_wrd = 0;
//         }
//         i++;
//     }
//     return (str_rtn);
// }

// void malloc_str_rtn(char **str_rtn, int word_ok, int letter, int l)
// {
//     if (word_ok != 0)
//         str_rtn[l] = malloc(sizeof(char) * letter + 1);
// }

// int count_words(char const *str, int word_ok, char **str_rtn)
// {
//     int i = 0;
//     int l = 0;
//     int letter = 0;
//     int word = 0;
//     for (i = 0; str[i] != '\0'; i++) {
//         if (check_alpha(str[i]) == 1) {
//             letter++;
//             if (str[i + 1] == '\0') {
//                 word++;
//                 malloc_str_rtn(str_rtn, word_ok, letter, l);
//             }
//         }
//         else if (letter > 0) {
//             if (word_ok != 0) {
//                     str_rtn[l] = malloc(sizeof(char) * letter + 1);
//                     l++;
//             }
//             word++;
//             letter = 0;
//         }
//     }
//     return (word);
// }

// char ** my_str_to_word_array(char const *str)
// {
//     int word = 0;
//     char **str_rtn;

//     str_rtn = malloc(sizeof(char *) * (count_words(str, 0, str_rtn) + 1));
//     word = count_words(str, word, str_rtn);
//     count_words(str, word, str_rtn);
//     str_rtn = store_words(str, str_rtn);
//     return (str_rtn);
// }
