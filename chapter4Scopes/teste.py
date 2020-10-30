lista = [7, 6, 3, 1, 2, 4]

def qsort(lista, left, right):
	if (left >= right):
		print("{} >= {}? R: {}".format(left, right, left >= right))	
		return;
	swap(lista, left, (left + right)/2);
	last
