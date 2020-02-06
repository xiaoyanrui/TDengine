#include <stdint.h>
#include <pthread.h>

#include "tsdb.h"
#include "disk.h"
#include "cache.h"

typedef struct STSDBRepo
{
    // TSDB configuration
    STSDBcfg *pCfg;

    /* Disk tier handle for multi-tier storage
     * 
     * The handle is responsible for dealing with object-oriented
     * storage.
     */
    SDiskTier *pDiskTier;

    /* Cache block list
     */
    SCacheBlock *pCacheBloclList;

    /* Map from tableId-->STable
     */
    STable *pTableList;

    /* Map from tableName->tableId
     * TODO: may use dict
     */
    void *pTableDict;

    /* Map from super tableName->table
     */
    void *pSTableDict;

    pthread_mutext_t tsdbMutex;

} STSDBRepo;

#define TSDB_GET_TABLE_BY_ID(pRepo, sid) (((STSDBRepo *)pRepo)->pTableList)[sid]
#define TSDB_GET_TABLE_BY_NAME(pRepo, name)
