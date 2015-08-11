#ifndef __FILEITEM_H_INCLUDED__
#define __FILEITEM_H_INCLUDED__

#include <string>

namespace SlamScan {
class FileItem;
}

class FileItem
{
public:
    FileItem(const std::string*);
    FileItem(const char*);
	void scan();
	__event void OnScanComplete(FileItem*);
	char* getName() { return &name; }
	char* getExtension() { return &ext; }
	long getSize() { return size; }

private:
	const char* path;
	char name;
	char ext;
	long size;
};

#endif
