#include "fileitem.h"
#include <sys/stat.h>

FileItem::FileItem(const std::string filename)
{
	struct stat stat_buf;
	int rc = stat(filename.c_str(), &stat_buf);
	size = rc == 0 ? stat_buf.st_size : -1;
}