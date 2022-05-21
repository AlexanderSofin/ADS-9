// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  {
    // поместите сюда свой код
    BST<string> tree;
    ifstream file(filename);
    if (!file)
    {
        throw string("file not found!");
    }
    string word = "";
    while (!file.eof())
    {
        char chr = file.get();
        int ascii = chr;
        if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122))
        {
            word += tolower(ascii);
        }
        else
        {
            if (word != "")
            {
                tree.add(word);
                word = "";
            }
        }
    }
    file.close();
    return tree;
}
}
