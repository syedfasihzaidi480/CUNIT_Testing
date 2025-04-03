/*
 * crc32.h
 *
 *  Created on: 25 Mar 2025
 *      Author: alij7
 */

#ifndef CRC_CRC32_H_
#define CRC_CRC32_H_

#include <sys/types.h>
#include <unistd.h>

extern uint32_t crc32_total;
int crc32(int fd, uint32_t *cval, uint32_t *clen);

#endif /* CRC_CRC32_H_ */
