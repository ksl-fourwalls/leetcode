#ifndef _BITSET_H_
#define _BITSET_H_ 1

typedef int64_t setCollection;

class BitSet {
	public:
		BitSet(int sets) 
		{
			size = (sets % MAX_BITS == 0) ? (sets / MAX_BITS) : (sets / MAX_BITS + 1);
			transition_cols = (setCollection*)calloc(MAX_BITS / CHAR_BIT, size);
		}
		~BitSet() 
		{
			free(transition_cols);
		}

		bool getBit(int which) 
		{
			size_t idx = which / MAX_BITS;
			assert(idx < size);
			return (transition_cols[idx] >> (which % MAX_BITS)) & 1;
		}

		void setBit(int which)
		{
			size_t idx = which / MAX_BITS;
			assert(idx < size);
			transition_cols[idx] |= (setCollection)1 << (which % MAX_BITS);
		}

		void printBitSet()
		{
			for (int idx = size-1; idx >= 0; idx--)
				printf("%016x", transition_cols[idx]);
		}

	private:
		setCollection *transition_cols;
		size_t size;
		const int MAX_BITS = 64;
};

#endif
