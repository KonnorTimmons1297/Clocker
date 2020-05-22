#include <stdio.h>

namespace util {


    char * readFile( const char * file_name ) {
        FILE *file = fopen( file_name, "r" );

        if ( !file ) {
            printf( "Unable to open file!\n" );
            exit( -1 );
        }

        //Get number of bytes in file
        fseek( file, 0L, SEEK_END );
        int num_bytes = ftell( file );
        fseek( file, 0L, SEEK_SET );

        char *file_data = (char*) calloc( num_bytes, sizeof(char) );

        if( file_data == NULL ) {
            printf( "Unable to allocate enough contiguous memory for file data!\n" );
            exit( -1 );
        }

        fread( file_data, sizeof(char), num_bytes, file );

        return file_data;
    }
}

