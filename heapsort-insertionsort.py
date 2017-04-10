import time
data = []
n = int(raw_input('Please enter the number of elements: '))
for i in range(1, n+1):
    x = (7 * i) % n
    data.append(x)
print(data)
#insertion sort
def insertion_sort(a):
	for index in range(1, len(a)):
		count = 0
		temp = a[index]
		pos = index-1
		while (pos >= 0) and (a[pos] > temp):
			a[pos+1] = a[pos]
			pos = pos - 1
			count += 1
		a[pos+1] = temp
	print("swapping times for insertion_sort:{} ".format(count))
	return a
# heap sort
count2 = 0
def swap(a, x, y):
    global count2
    temp = a[x]
    a[x] = a[y]
    a[y] = temp
    count2 += 1
def siftDown(a, start, end):
    # right child
    right = 2 * start +1
    while right <= end:
        if (right < end) and (a[right] < a[right+1]):
            right += 1
        # right child larger than parent
        elif a[right] > a[start]:
            swap(a, right, start)
            # exchange
            start = right
            right = 2*start + 1
        else:
            return


# heap sort
def heap_sort(a):
    # heapify
    global count2
    length = len(a) - 1
    parent = length / 2
    for i in range(parent, -1, -1):
        siftDown(a, i, length)
    # exchange
    for i in range(length, 0, -1):
        if a[0] > a[i]:
            swap(a, 0, i)
            siftDown(a, 0, i-1)
    print("swpping times for heap_sort:{}".format(count2))

if __name__ == "__main__":
    start_insert = time.time()
    insertion_sort(data)
    end_insert = time.time()
    print("insertion_sort running time: %f" % (end_insert - start_insert))
    start_heap = time.time()
    heap_sort(data)
    end_heap = time.time()
    print("heap_sort running time: %f" % (end_heap - start_heap))
    #print("insertion_sort output:")
    #print(data)
    #print("heap_sort output:")
    #print(data)
