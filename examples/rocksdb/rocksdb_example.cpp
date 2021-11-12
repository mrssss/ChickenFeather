#include <iostream>
#include <string>
#include <rocksdb/db.h>

using namespace std;

int main() {
    rocksdb::DB * db;
    rocksdb::Options options;

    options.create_if_missing = true;

    rocksdb::Status status = rocksdb::DB::Open(options, "testdb.db", &db);
    std::cout << "Open db status: " << status.ok() << std::endl;

    status = db->Put(rocksdb::WriteOptions(), "Test key", "Test value");
    std::cout << "Put db status: " << status.ok() << std::endl;

    std::string value;
    status = db->Get(rocksdb::ReadOptions(), "Test key", &value);
    std::cout << "Get db status: " << status.ok() << std::endl;
    std::cout << "Get db is not found: " << status.IsNotFound() << std::endl;
    std::cout << "value: " << value << std::endl;

    status = db->Get(rocksdb::ReadOptions(), "This key does not exist", &value);
    std::cout << "Get db status: " << status.ok() << std::endl;
    std::cout << "Get db is not found: " << status.IsNotFound() << std::endl;
    std::cout << "value: " << value << std::endl;

    return 0;
}