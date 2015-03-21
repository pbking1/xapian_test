#include<iostream>
#include<string>
#include<xapian.h>

using namespace std;

#define DB_PATH "index_data"
#define QUERY "king"
#define CLASS 1

int main(){
	//open database and handle searh
	string dbpath(DB_PATH);
	Xapian::Database db;
	Xapian::Enquire enquire(db);

	//Parser Query
	Xapian::QueryParser qp;
	Xapian::Query query = qp.parse_query("king");
	cout<<"Query:\t"<<query.get_description()<<endl;

	//Set Query & Match Filter
	enquire.set_query(query);
	Xapian::ValueSetMatchDecider md(CLASS, true);
	md.add_value(string("2"));
	//Xapian::MSet result = enquire.get_mset(0, 10, NULL, &md);
	Xapian::MSet result = enquire.get_mset(0, 10);

	//Print results
	for(Xapian::MSetIterator iter = result.begin(); iter != result.end(); iter++){
		Xapian::Document doc = iter.get_document();
		cout<<iter.get_rank()<<","<<doc.get_data()<<endl;
	}

	return 0;
}
