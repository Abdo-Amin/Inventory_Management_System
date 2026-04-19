#ifndef IMS_DEBUG_H
#define IMS_DEBUG_H

/**
 * Recursively deletes the entire "ims" directory and all its contents.
 * Intended for development/debugging to reset application state.
 * WARNING: This operation is destructive and results in permanent data loss.
 * Must not be used in production builds.
 */
void deleteIMSDirectory();

#endif