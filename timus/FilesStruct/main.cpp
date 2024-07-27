#include <iostream>
#include <map>
#include <sstream>

using namespace std;


struct directory {
    map<string, struct directory*> childDirectory;
};

void print(struct directory* dir, string spaces) {
    string nextSpace = spaces + " ";
    if (!dir->childDirectory.empty()) {
        for (auto it : dir->childDirectory) {
            cout << spaces << it.first << endl;
            print(it.second, nextSpace);
        }
    }
}

int main() {
    struct directory root = {};
    struct directory* current;
    string path, folderName;
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        current = &root;
        cin >> path;
        stringstream ss(path);
        while (getline(ss, folderName, '\\')) {
            if (current->childDirectory.find(folderName) != current->childDirectory.end()) {
                current = current->childDirectory[folderName];
            } else {
                current->childDirectory[folderName] = new struct directory;
                current = current->childDirectory[folderName];
            }
        }
    }
    print(&root, "");
    return 0;
}
