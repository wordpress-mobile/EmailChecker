
#include "EmailDomainSpellChecker.h"
#include <iostream>

const static unordered_set<std::string> sModel = {
    "gmail.com",
    "yahoo.com",
    "hotmail.com",
    "outlook.com",
    "comcast.com",
};

#pragma mark - Constructors and destructore

EmailDomainSpellChecker::EmailDomainSpellChecker() {
}

#pragma mark - Private methods

string EmailDomainSpellChecker::suggest(const string &word) {
    unordered_set<string> candidates;
    unordered_set<string> results;
    
    // word is not mispelled
    if (sModel.find(word) != sModel.end()) {
        return word;
    }
    
    // add edited and known words the results
    edits(word, results);
    known(results, candidates);
    
    if (candidates.size() > 0) {
        return *candidates.begin();
    }

    // second step edits (edits of edits) if nothing found previously
    for (unordered_set<string>::const_iterator i = results.begin(); i != results.end(); i++) {
        unordered_set<string> secondStepResults;
        edits(*i, secondStepResults);
        known(secondStepResults, candidates);
        if (candidates.size() > 0) {
            return *candidates.begin();
        }
    }
    return "";
}

void EmailDomainSpellChecker::known(const unordered_set<string> &words, unordered_set<string> &results) {
    for (unordered_set<string>::const_iterator i = words.begin(); i != words.end(); i++) {
        if (sModel.find(*i) != sModel.end()) {
            results.insert(*i);
        }
    }
}

void EmailDomainSpellChecker::edits(const string &word, unordered_set<string> &results) {
    // deletes
    for (size_t i = 0;i < word.size(); i++) {
        results.insert(word.substr(0, i) + word.substr(i + 1));
    }
    // transposes
    for (size_t i = 0;i < word.size() - 1;i++) {
        results.insert(word.substr(0, i) + word[i + 1] + word.substr(i + 2));
    }
    // replaces
    for (size_t i = 0; i < word.size(); i++) {
        for (char j = 'a'; j <= 'z'; ++j) {
            results.insert(word.substr(0, i) + j + word.substr(i + 1));
        }
    }
    // inserts
    for (size_t i = 0; i < word.size() + 1; i++) {
        for (char j = 'a'; j <= 'z'; ++j) {
            results.insert(word.substr(0, i) + j + word.substr(i));
        }
    }
}

#pragma mark - Public methods

string EmailDomainSpellChecker::suggestDomainCorrection(const string &emailAddress) {
    size_t atCharPosition = emailAddress.find('@');
    string extractedDomain = string(emailAddress.data() + atCharPosition + 1);
    // don't check domain name shorter than 1 char
    if (extractedDomain.size() <= 1) {
        return emailAddress;
    }
    string suggestion = suggest(extractedDomain);
    // If domain suggestion is the same as original, return original email address or not found
    if (suggestion.compare(extractedDomain) == 0 || suggestion.size() == 0) {
        return emailAddress;
    }
    // construct return string
    return emailAddress.substr(0, atCharPosition + 1) + suggestion;
}
