#include<xapian.h>
#include<iostream>
#include<string>
using namespace std;

#define CONTENT "70:69， This is man basketball race history the smallest point difference race ， smile to last is east man Chinese 。 Which can be said ， This time is the most famous victory and can be said this is the most lucky resuly 。After the end of the game, the coach of the Chinese aa and The boss bb hang togetherm and the two guy are so happy that the chinese win。"

#define TITLE "This is a news"

#define INDEX_PATH "./index_data"

#define F_DOCID 1

int main(int argc, char *argv[]){
	try{
		//The text to be indexed
		string content(CONTENT);
		string title(TITLE);

		//open a database and write
		Xapian::WritableDatabase db(string(INDEX_PATH), Xapian::DB_CREATE_OR_OPEN);
		
		//term generator
		Xapian::TermGenerator indexer;

		//Make document
		Xapian::Document doc;
		doc.add_value(F_DOCID, string("1104"));
		doc.set_data(content);
		indexer.set_document(doc);
		indexer.index_text(title, 1, "T");
		indexer.index_text(content, 1, "C");

		//add document to db
		db.add_document(doc);

		//flush to disk
		db.commit();

	}catch(const Xapian::Error &e){
		cout<<e.get_description()<<endl;
	}
	return 0;
}
