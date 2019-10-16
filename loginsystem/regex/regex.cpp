#include "regex.h"

int main()
{ // Part 1 cached:
    // std::regex xeger{R"((?:\t_a:e+t/r){4})"};
    //std::string word = "\t_a:et/r\t_a:et/r\t_a:et/r\t_a:et/r";

    /*  
    ab?c

    ? = 0 or 1 times
    + = at least 1 time
    * 0 or more
    . any char
    (?:abc[def])esfkogjrdly\1{}
    [abcde]

    */

    // step 2 cached
    // std::regex xeger{R"((?:hex)(\t_a:e+t/r){4}[^[:lower:]]{3}!?&+[[:punct:]^]+\1{2})"};
    // std::string word = "hex\t_a:et/r\t_a:et/r\t_a:et/r\t_a:et/rAAC!&&^;.\t_a:et/r\t_a:et/r";
    // std::regex xeger{R"((?:std::hex)(?:w?)?(\t_a:e+t/r){4}[^[:lower:]]{3}!?&+[[:punct:]^]+\1{2})"};
    // std::string word = "std::hex\t_a:et/r\t_a:et/r\t_a:et/r\t_a:et/rAAC!&&^;.\t_a:et/r\t_a:et/rxa&%!     ¢-";

    // step 3
    // std::regex xeger{R"(x[^erd].{4}&%!(?:¢:65[[:s:]]{7}){4}-)"};
    // std::string word = "xafedr&%!¢:65       ¢:65       ¢:65       ¢:65       -";

    std::string username = "alice";
    int random = 453643636;
    std::stringstream ss;
    ss << "(?:_-_-_-__-_-:" << random << "#€@){" << username.length() << "}a";
    std::string usernamelengthpattern = ss.str();
    std::string hi = R"((?:std::hex)(?:w?)?(\t_a:e+t/r){4}[^[:lower:]]{3}!?&+[[:punct:]^]+\1{2}x£[^erd].{4}&%!(?:¢:65?43[[:s:]]{7}){4}\1-)" + ss.str();
    //std::regex xeger{R"((?:std::hex)(?:w?)?(\t_a:e+t/r){4}[^[:lower:]]{3}!?&+[[:punct:]^]+\1{2}x[^erd].{4}&%!(?:¢:65?43[[:s:]]{7}){4}-)"};
    std::string word = "std::hex\t_a:et/r\t_a:et/r\t_a:et/r\t_a:et/rAAC!&&^;.\t_a:et/r\t_a:et/rx£afedr&%!¢:643       ¢:643       ¢:643       ¢:643       \t_a:et/r-_-_-_-__-_-:453643636#€@_-_-_-__-_-:453643636#€@_-_-_-__-_-:453643636#€@_-_-_-__-_-:453643636#€@_-_-_-__-_-:453643636#€@a";

    std::regex unregex{hi};
    std::string pword = "_-_-_-__-_-:#€@_-_-_-__-_-:#€@_-_-_-__-_-:#€@_-_-_-__-_-:#€@_-_-_-__-_-:#€@a";

    bool matched = std::regex_match(word, unregex);
    // bool matched = std::regex_match(word, xeger);

    std::cout << matched << std::endl;

    // alphabet:
    // abcdefghijklmnopqrstuvwxyz
    // not m

    // TODO: use username length somewhere, mins % 3  + 1
    // use (abc|def)=\1 matches abc=abc or def=def, but not abc=def or def=abc. a few times referencing forwards & backwards to confuse them
    // Check meaning of (?:) -> does this include : in the group? if so miss it out once for the fun of it
    /*
        (?:\t_a:e+t/r){4}                                   # exact sequence of \t_a:et/r * 4  (group = \1 for future use)
            \L{3}                                           # Any non-lowercase char * 3
                :[^aipfrsgudqvytzjhexnkclob]+               # :[NOT any of aipfrsgudqvytzjhexnkclob]+ (at least once)
                    ...                                     # tbc
                        (?:\S[:xdigit]{$LENGTHOFUSERNAME})  # any hex char 0-9-a-f length of un times  -> group \G
                        [^\d]?                              # any Non-digit (ie 0-9), 0 or 1 times no more.
                            \G                              # repeat \G
                            [e^r]+                          # e or ^ or r at least once (^ is ^ doesnt mean not here!)
                                (?:                         # open group \N
                                    [:alpha:]               # any alphabetic character
                                    [^[:alnum:]]{5})        # any nonalphanumeric character x5 (closed GROUP IS \N in its entirety as used!)
                                    =:?                     # =:?
                                        \1                  # group 1 :  tab((_a:e+r/t|_s*))


    */
}
