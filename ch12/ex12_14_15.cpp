/*
Exercise 12.14: Write your own version of a function that uses a
shared_ptr to manage a connection.
Exercise 12.15: Rewrite the first exercise to use a lambda (§ 10.3.2, p.
388) in place of the end_connection function.
*/

#include <iostream>
#include <memory>
using namespace std;

struct destination{};  // represents what we are connecting
struct connection{};   // information needed to use the connection

connection connect(destination*)  // open the connection
{
	connection conn;
	return conn;
}

void disconnect(connection conn); // close the given connection

void end_connection(connection *p)
{
	disconnect(*p);
}

void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, end_connection);

	// ex12_15:
	// shared_ptr<connection> p_conn(&c, [](connection *p_c){ disconnect(*p_c); });
}

int main(int argc, char const *argv[])
{
	return 0;
}