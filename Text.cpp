/* W10 LAB
   Name: Shuqi Yang
   Std ID: 132162207
   Email: syang136@myseneca.ca
   Date: 04-08-2021
   -------------------------------------------------------
   I have done all the coding by myself and only copied the
   code that my professor provided to complete my workshops
   and assignments.
 */
#include <fstream>
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }
   const char& Text::operator[](int index)const {
       return m_content[index];
   }
   Text::Text(const char* filename) {
       if (filename == nullptr) {
           m_filename = nullptr;
           m_content = nullptr;
       }
       else {
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
           read();
       } 
   }
   Text::Text(const Text& t) {
       if (t.m_filename != nullptr){
           m_filename = new char[strLen(t.m_filename) + 1];
           strCpy(m_filename, t.m_filename);
           read();
       }
       else {
           m_filename = nullptr;
           m_content = nullptr;           
       }
   }
   Text& Text::operator=(const Text& t) {
       if (this != &t) {
           delete[] m_filename;
           m_filename = new char[strLen(t.m_filename) + 1];
           strCpy(m_filename, t.m_filename);
           read();
       }
       return *this;
   }
   Text::~Text() {
       delete[] m_filename;
       delete[] m_content;
   }
   void Text::read() {
       delete[] m_content;
       int f_length = getFileLength();
       m_content = new char[f_length + 1];
       char input;
       ifstream fin(m_filename);
       int i = 0;
       while (fin) {
           fin >> noskipws >> input;
           if(fin){
               m_content[i] = input;
               i++;
           }
       }
       m_content[i] = '\0';
       fin.close();    
   }
   void Text::write(std::ostream& os)const {
       if (m_content != nullptr) {
           os << m_content;
       }
   }
   std::ostream& operator<<(std::ostream& os, const Text& t) {
       t.write(os);
       return os;
   }
};

