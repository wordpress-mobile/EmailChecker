#ifndef _DOMAINEMAILSPELLCHECKER_H_
#define _DOMAINEMAILSPELLCHECKER_H_

#include <string>
#include <unordered_set>

#define private public

using namespace std;

class EmailDomainSpellChecker {
private:
    unordered_set<string> mModel;

private:
    void known(const unordered_set<string> &words, unordered_set<string> &results);
    void edits(const string &word, unordered_set<string> &results);
    string suggest(const string &word);
    string extractDomain(const string &word);

public:
    EmailDomainSpellChecker();
    void init();
    string suggestDomainCorrection(const string &word);
};

#endif
