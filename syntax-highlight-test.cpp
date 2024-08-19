int (*fun(int x, int y))[2] {
	array[0] = x;
	array[1] = y;
	return &array;
}

int main() {
	int (*a)[2] { fun(1, 2) };
	cout << (*a)[0] + (*a)[1] << endl;
}
