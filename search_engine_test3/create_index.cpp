#include<iostream>
#include<string>
#include<xapian.h>
using namespace std;

#define DB_PATH "index_data"
#define TEXT1 "I am king 1"
#define TEXT2 "I am king 2"
#define CLASS 1

int main(){
	//open the database
	string dbpath(DB_PATH);
	Xapian::WritableDatabase db(dbpath, Xapian::DB_CREATE_OR_OPEN);
	Xapian::TermGenerator indexer;

	//create document 1
	Xapian::Document doc1;
	doc1.add_value(CLASS, "1");
	string text1(TEXT1);
	doc1.set_data(text1);
	indexer.set_document(doc1);
	indexer.index_text(text1);
	db.add_document(doc1);

	Xapian::Document doc2;
	doc2.add_value(CLASS, "1");
	string text2(TEXT2);
	doc2.set_data(text2);
	indexer.set_document(doc2);
	indexer.index_text(text2);
	db.add_document(doc2);

	db.commit();

	return 0;
}
