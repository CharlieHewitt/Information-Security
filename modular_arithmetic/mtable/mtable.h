#include <sstream>

typedef std::stringstream sstream;

void printHeader(int, sstream *);
void printHeaderEnd(int, sstream *ss);
void printRow(int i, int n, sstream *ss);
void printRows(int n, sstream *ss);
