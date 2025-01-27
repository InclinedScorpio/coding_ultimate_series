#include <bits/stdc++.h>
using namespace std;
// Make a in memory file system

enum FILE_TYPE {
    PDF,
    IMAGE,
    EXCEL,
    CPP,
    DIRECTORY
};

class File {
    string name;
    int size;
    FILE_TYPE type;
    bool isDirectory;
    
    public:
    vector<File*> childrens;
    File(string name, int size, FILE_TYPE type, bool isDirectory): name(name), size(size), type(type), isDirectory(isDirectory) {} 
    
    void addFileToDirectory(File* newFile) {
        if(this->isDirectory) {
            this->childrens.push_back(newFile);
        } else {
            cout<<"... oops! This is not a directory";
        }
    }
    
    string getFileName() const {
        return this->name;
    }
    
    int getFileSize() const {
        return this->size;
    }
    
    FILE_TYPE getFileType() const {
        return this->type;
    }
    
    bool getIsDirectory() const {
        return this->isDirectory;
    }
};

// interface...
class Filters {
    public:
    virtual bool apply(const File* myF) const =0;
};

class SizeFilter: public Filters {
    private:
    int size;
    bool moreThan;
    
    public:
    SizeFilter(int size, bool moreThan=true){
        this->size = size;
        this->moreThan = moreThan;
    };
    bool apply(const File* file) const {
        if(moreThan) {
            return file->getFileSize() > this->size;
        }
        return file->getFileSize() <= this->size;
    }
};

class TypeFilter: public Filters {
    FILE_TYPE type;
    public:
    TypeFilter(FILE_TYPE type): type(type){}
    
    bool apply(const File* file) const {
        return file->getFileType() == type;
    }
};

class FileManager {
    private:
    FileManager(){}
    public:
    inline static File* root=nullptr;
    
    static vector<const File*> filterFiles(vector<Filters*> filters) {
        vector<const File*> output;
        findFiles(root, filters, output);
        return output;
    }
    
    static void findFiles(const File* root, const vector<Filters*>& filters, vector<const File*>& output) {
        if(!root) return;
        
        
        for(const File* file: root->childrens) {
            if(file->getIsDirectory()) {
                findFiles(file, filters, output);
            } else {
                // means it's a file
                bool includeFile=false;
                for(const Filters* filter: filters) {
                    if(filter->apply(file)) {
                        includeFile=true;
                    }
                }
                if(includeFile) {
                    output.push_back(file);
                }
            }
        }
    }
};


int main() {
    File* root = new File("root", 0, FILE_TYPE::DIRECTORY, true);
    File* insideRoot = new File("insideRoot", 0, FILE_TYPE::DIRECTORY, true);
    
    
    File* file1 = new File("file1", 20, FILE_TYPE::PDF, false);
    root->addFileToDirectory(insideRoot);
    root->addFileToDirectory(file1);
    
    File* file2 = new File("file2", 40, FILE_TYPE::IMAGE, false);
    File* file3 = new File("file3", 70, FILE_TYPE::EXCEL, false);
    insideRoot->addFileToDirectory(file2);
    insideRoot->addFileToDirectory(file3);
    
    FileManager::root=root;
    
    // SET FILE SIZE BELOW FOR FILTERING
    SizeFilter ssF(50);
    // SET TYPE OF FILTER BELOW
    TypeFilter ttF(FILE_TYPE::IMAGE);
    vector<Filters*> fill;
    fill.push_back(&ssF);
    fill.push_back(&ttF);

    vector<const File*> files = FileManager::filterFiles(fill);
    cout<<"extracted files...."<<endl;
    for(const File* f: files) {
        cout<<" -> "<<f->getFileName()<<endl;
    }
    return 0;
}
