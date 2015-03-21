#include<xapian.h>
#include<iostream>
#include<string>
using namespace std;

#define QUERY "title:news AND content:70"

#define INDEX_PATH "./index_data"

#define F_DOCID 1

int main(){
	try{
		//The string for query
		string query_str(QUERY);

		//open the database
		Xapian::Database db(string(INDEX_PATH));

		//open search handle
		Xapian::Enquire enquire(db);

		//Parser Query
		Xapian::QueryParser qp;
		qp.add_prefix("title", "T");
		qp.add_prefix("content", "C");
		Xapian::Query query = qp.parse_query(query_str);
		cout<<"Query is "<<query.get_description()<<endl;

		//find the top 10 result
		enquire.set_query(query);
		Xapian::MSet result = enquire.get_mset(0,10);
		cout<<result.get_matches_estimated()<<" result found"<<endl;

		//print the result
		for(Xapian::MSetIterator iter = result.begin(); iter != result.end(); iter++){
			Xapian::Document doc = iter.get_document();
			cout<<iter.get_rank()<<": docid "<<doc.get_value(F_DOCID)<<", data"<<doc.get_data()<<endl;
		}

	}catch(const Xapian::Error e){
		cout<<e.get_description()<<endl;
	}
	return 0;
}
