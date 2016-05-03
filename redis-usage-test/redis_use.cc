#include <iostream>
#include <string.h>
#include <hiredis/hiredis.h>
#include <stdlib.h>
using namespace std;

int main()
{
	redisContext* c = redisConnect("127.0.0.1", 6379);
	if(c->err){
		redisFree(c);
		cout << "Connect to redisServer failed" << endl;
		exit(-1);
	}
	cout << "Connect to redisServer success" << endl;
	string command1("set test1 value1");
	redisReply* r = (redisReply*)redisCommand(c, command1.c_str());

	if(r==NULL){
		printf("execut command1 failure");
		redisFree(c);
		exit(-1);
	}
	if(!(r->type==REDIS_REPLY_STATUS && strcasecmp(r->str,"OK")==0)){
		cout << "failed to excute command[" << command1 << "]" << endl;
		freeReplyObject(r);
		redisFree(c);
		exit(-1);
	}
	cout << "excute command[" << command1 << "]succeed" << endl;
	freeReplyObject(r);

	string command2("strlen test1");
	r = (redisReply *)redisCommand(c, command2.c_str());
	if(r->type != REDIS_REPLY_INTEGER){
        cout << "failed to excute command[" << command2 << "]" << endl;
		freeReplyObject(r);
		redisFree(c);
		exit(-1);
	}
	int length = r->integer;
	freeReplyObject(r);
	cout << "the length of 'test1' is " << length << endl;
	cout << "excute command[" << command2 << "]succeed" << endl;

	string command3("get test1");
	r = (redisReply *)redisCommand(c, command3.c_str());
	if(r->type != REDIS_REPLY_STRING){
        cout << "failed to excute command[" << command3 << "]" << endl;
		freeReplyObject(r);
		redisFree(c);
		exit(-1);
	}
	cout << "the value of 'test1' is " << r->str << endl;
	freeReplyObject(r);
	cout << "excute command[" << command3 << "]succeed" << endl;
	
	string command4("get test2");
	r = (redisReply *)redisCommand(c, command4.c_str());
	if(r->type != REDIS_REPLY_NIL){
        cout << "failed to excute command[" << command4 << "]" << endl;
		freeReplyObject(r);
		redisFree(c);
		exit(-1);
	}
	freeReplyObject(r);
	cout << "excute command[" << command3 << "]succeed" << endl;

	string shutdown("shutdown");
	redisCommand(c, shutdown.c_str());
	redisFree(c);
	exit(0);
}
