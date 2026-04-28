#ifndef IMS_SPU_H
#define IMS_SPU_H

#include <string>

/**
 * Checks whether the Special User (SPU) configuration file exists.
 * Used during application startup to determine if initial setup is required.
 * @return True if the SPU file exists, false otherwise.
 */
bool isSPUFound();

/**
 * Creates the required directory structure and writes SPU credentials
 * to the configuration file. Existing file contents will be overwritten.
 * @param spuName Username to be stored.
 * @param spuPasswd Password to be stored.
 */
void initiateSPU(std::string spuName, std::string spuPasswd);

/**
 * Handles the SPU initialization workflow.
 * Displays a welcome message and triggers setup if no SPU file is found.
 */
void startSPU();

#endif