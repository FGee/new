#include <func.h>

int main(int argc, char ** argv)
{
    ARGS_CHECK(argc, 2);
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char* server = "localhost";
    char* user = "root";
    char* password = "456456";
    char* database = "Course";
    char query[200] = "update sel_cour set ";
    sprintf(query, "%s%s", query, argv[1]);
    puts(query);
    int t, r;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        printf("Error connecting to database:%s\n", mysql_error(conn));
    } else {
        printf("Connected...\n");
    }
    t = mysql_query(conn, query);
    if (t) {
        printf("Error making query:%s\n", mysql_error(conn));
    } else {
        printf("update success\n");
    }
    mysql_close(conn);

    return 0;
}

