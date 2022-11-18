```cpp
// FileSize = 100(in GB), ramSize = 4(in GB), pageSize =
// 4(in MB)
Void merge(int fileSize, int ramSize, int pageSize)
{
	int chunks = fileSize / ramSize;
	int chunksize = fileSize / chunks;
	
	for (int i = 0; i < chunks; i++) {
		int curr = i * ramSize * 1024;
		while (curr <= 4 * 1024) {
			Read(curr);
			Curr += pageSize;
		}
		Sort();
		curr = i * ramSize * 1024;
		Int pos = 0;
		while (pos < ramSize * 1024) {
			Write(pos, curr);
			Curr += pageSize;
		}
	}

	// now merge sorted chunks
	Int cur = 0;
	int* ptr = new int[chunks];
	for (int i = 0; i < chunks; i++)
		Ptr[i] = 0;

	priority_queue(pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>) pq;

	for (int i = 0; i < chunks; i++) {
		Read(ptr[i]);
		Ptr[i] += pageSize;
		For(every element k in page)
		{
			pq.push_back(make_pair(k, i));
		}
	}

	int* curr = new int[chunks];
	for (int i = 0; i < chunks; i++)
		curr[i] = 0;

	Int k = 0;
	// Output buffer
	while (!pq.isEmpty()) {
		pair<int, int> p = pq.top();
		pq.pop();
		Int idx = p.second Output[k++]
			= p.first curr[idx]++;
		Int limit = pageSize / sizeof(int);
		if (curr[idx] == limit) {
			Curr[idx] = 0;
			if (ptr[i] != chunkSize) {
				Read(ptr[i]);
				Ptr[i] += pageSize;
				For(every element k in page)
				{
					pq.push_back(make_pair(k, idx));
				}
				Write(output to disk)
			}
		}
	}
	// Pop top element and store in output space
	// If a page is emptied then bring next page
	// from that chunk
	// If ram is about to be filled then store the
	// sorted file back to disk
}
```
