#ifndef __FILEITEM_H_INCLUDED__
#define __FILEITEM_H_INCLUDED__

#include <string>

class FileItem
{
public:
	FileItem(const std::string);
	char* getName() { return name; }
	char* getExtension() { return ext; }
	long getSize() { return size; }

private:
	char* name;
	char* ext;
	long size;
};

#endif