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
#include "HtmlText.h"
#include "cstring.h"
namespace sdds {
    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename){
        if (title != nullptr) {
            m_title = new char[strLen(title) + 1];
            strCpy(m_title, title);
        }
        else {
            m_title = nullptr;
        }
    }
    HtmlText::HtmlText(const HtmlText& ht) : Text(ht) {
        if (ht.m_title != nullptr && this!=&ht) {
            m_title = new char[strLen(ht.m_title) + 1];
            strCpy(m_title, ht.m_title);
        }
    }
    HtmlText& HtmlText::operator=(HtmlText& ht) {
        if (this != &ht) {
            Text::operator=(ht);
            delete[] m_title;
            m_title = new char[strLen(ht.m_title) + 1];
            strCpy(m_title, ht.m_title);
        }
        return *this;
    }
    HtmlText::~HtmlText() {
        delete[] m_title;
    }
    void HtmlText::write(std::ostream& os)const {
        bool ms = false;
        os << "<html><head><title>" << (m_title == nullptr ? "No Title" : m_title) << "</title></head>\n<body>\n";
        if (m_title != nullptr) {
            os << "<h1>" << m_title << "</h1>\n";
        }
        int i = 0;
        while ((*this)[i] != '\0') {
            switch ((*this)[i]) {
            case ' ':
                if (ms) {
                    os << "&nbsp;";
                }
                else {
                    ms = true;
                    os << ' ';
                }
                break;
            case '<':
                os << "&lt;";
                ms = false;
                break;
            case '>':
                os << "&gt;";
                ms = false;
                break;
            case '\n':
                os << "<br />\n";
                ms = false;
                break;
            default:
                ms = false;
                os << (*this)[i];
            }
            i++;
        }
        os << "</body>\n</html>";
    }
}