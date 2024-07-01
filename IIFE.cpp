#include <iostream>
#include "utils/tinyxml2.h"
#include "utils/tinyxml2.cpp"

int main() {

  // exemplo a ser substituido: quer-se ler de um xml
  tinyxml2::XMLDocument doc;
  doc.LoadFile( "utils/example.xml" );

  const char *data1 = doc.FirstChildElement("document")->FirstChildElement("data")->GetText();

  std::cout << data1 << '\n';

  // mas usando IIFE
  const char *data2 = [](const char* file = "utils/example.xml"){

    tinyxml2::XMLDocument doc1;
	  doc1.LoadFile( file );

    return doc1.FirstChildElement("document")->FirstChildElement()->NextSiblingElement()->GetText();
  }();

  std::cout << data2 << '\n';



  return 0;
}