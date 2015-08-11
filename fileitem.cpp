#include "fileitem.h"
#include <sys/stat.h>

FileItem::FileItem(const std::string* filename) : path((*filename).c_str())
{
}

FileItem::FileItem(const char* filename) : path(filename)
{
}

void FileItem::scan()
{
	struct stat stat_buf;
	int rc = stat(path, &stat_buf);
	size = rc == 0 ? stat_buf.st_size : -1;

	OnScanComplete(this);
}
