#ifndef PRIME_H
#define PRIME_H

int is_prime( const int x );
int next_prime( int x );
int previous_prime( int x );
int* sieve_of_eratosthenes( unsigned int limit, int* length ); 
int* prime_factors( unsigned int num, int* num_factors );
int num_prime_factors( unsigned int num );

#endif
