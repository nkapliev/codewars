#include <printf.h>
#include <stdlib.h>
#include <regex.h>
#include <stdio.h>


/* Return 1 is addr is a valid IP address, return 0 otherwise */
int is_valid_ip(const char * addr) {
    char * regex_src =
            "^(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\."
                    "(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\."
                    "(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\."
                    "(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$";
    regex_t regex;
    int reti;
    char msgbuf[100];
    int result;

    reti = regcomp(&regex, regex_src, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    reti = regexec(&regex, addr, 0, NULL, 0);
    if (!reti) result = 1;
    else if (reti == REG_NOMATCH) result = 0;
    else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }

    regfree(&regex);

    return result;
};

int main () {
    char * valid_ips[5] = {
            "192.168.1.1",
            "1.1.1.1",
            "0.0.0.0",
            "192.0.0.1",
            "255.255.255.255"
    };
    char * invalid_ips[5] = {
            "01.1.1.1",
            "",
            "1",
            "...",
            "256.1.1.1"
    };

    printf("Valid tests:\n");
    for (int i = 0, size = sizeof(valid_ips) / sizeof(valid_ips[0]); i < size; i++)
        printf("%s: %d\n", valid_ips[i], is_valid_ip(valid_ips[i]));

    printf("Invalid tests:\n");
    for (int i = 0, size = sizeof(invalid_ips) / sizeof(invalid_ips[0]); i < size; i++)
        printf("%s: %d\n", invalid_ips[i], is_valid_ip(invalid_ips[i]));
}

// Define the prototype for the solution function
//int is_valid_ip(const char * addr);

//Test(misc, failing) {
//    cr_assert(0);
//}

// Perform some example tests
//Test(is_valid_ip, example_tests) {
//    cr_expect_eq(is_valid_ip("12.255.56.1"), 1, "\"%s\" IS a valid IP", "12.255.56.1");
//    cr_expect_eq(is_valid_ip(""), 0, "\"%s\" IS a valid IP", "");
//    cr_expect_eq(is_valid_ip("abc.def.ghi.jkl"), 0, "\"%s\" IS a valid IP", "abc.def.ghi.jkl");
//    cr_expect_eq(is_valid_ip("123.456.789.0"), 0, "\"%s\" IS a valid IP", "123.456.789.0");
//    cr_expect_eq(is_valid_ip("12.34.56"), 0, "\"%s\" IS a valid IP", "12.34.56");
//    cr_expect_eq(is_valid_ip("12.34.56 .1"), 0, "\"%s\" IS a valid IP", "12.34.56 .1");
//    cr_expect_eq(is_valid_ip("12.34.56.-1"), 0, "\"%s\" IS a valid IP", "12.34.56.-1");
//    cr_expect_eq(is_valid_ip("123.045.067.089"), 0, "\"%s\" IS a valid IP", "123.045.067.089");
//};
