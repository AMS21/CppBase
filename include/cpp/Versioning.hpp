#ifndef INCG_CPPBASE_VERSIONING_HPP
#define INCG_CPPBASE_VERSIONING_HPP

#define CPP_VERSION_CREATE(major, minor, patch) (((major) << 24) + ((minor) << 16) + (patch))

#define CPP_VERSION_EXTRACT_MAJOR(version) ((version) >> 24)

#define CPP_VERSION_EXTRACT_MINOR(version) (((version) >> 16) % 256)

#define CPP_VERSION_EXTRACT_PATCH(version) ((version) % 256)

#endif // INCG_CPPBASE_VERSIONING_HPP
