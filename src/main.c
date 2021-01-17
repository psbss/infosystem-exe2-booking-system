#include "mylib.h"

int main(int argc, char *argv[]){
	printf("program started \n");
	int database[DATABASE_NUMBER][DATABASE_TYPE];
	int db_mon_am[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_mon_pm[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_tue_am[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_tue_pm[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_thu_am[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_thu_pm[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_sat_am[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_sat_pm[DATABASE_BLOCK_NUMBER][DATABASE_TYPE];
	int db_block_no = 0;
	int id[DATABASE_BLOCK_NUMBER];
	int id_copy[DATABASE_BLOCK_NUMBER];
	int result[DATABASE_BLOCK_NUMBER];
	double_array_init(DATABASE_NUMBER, DATABASE_TYPE, database);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_mon_am);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_mon_pm);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_tue_am);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_tue_pm);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_thu_am);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_thu_pm);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_sat_am);
	double_array_init(DATABASE_BLOCK_NUMBER, DATABASE_TYPE, db_sat_pm);
	array_init(DATABASE_BLOCK_NUMBER, id);
	array_init(DATABASE_BLOCK_NUMBER, id_copy);
	array_init(DATABASE_BLOCK_NUMBER, result);

	printf("array_init finished! \n");

	if (argc == 2 && !strcmp(argv[1], "-m")){
		inquiry();
		printf("inquiry finished! \n");
	} else if (argc == 2 && !strcmp(argv[1], "-t")) {
		test_inquiry(DATABASE_NUMBER, DATABASE_TYPE, database);
	} else {
		random_inquiry(DATABASE_NUMBER, DATABASE_TYPE, database);
		printf("random_inquiry finished! \n");
	}

	add_exeopetime(DATABASE_TYPE, 1, 4, 5, DATABASE_NUMBER, database);
	shaker_sort_double_arr(DATABASE_TYPE, 2, DATABASE_NUMBER, database);
	separate_arr(DATABASE_TYPE, 2, database, db_mon_am, db_mon_pm, db_tue_am, db_tue_pm, db_thu_am, db_thu_pm, db_sat_am, db_sat_pm);

	print_double_arr(DATABASE_NUMBER, DATABASE_TYPE, database);
	print_newline(2);

	db_block_no = arr_len(DATABASE_TYPE, db_mon_am);
	arr_copy(DATABASE_TYPE, db_block_no, 0, db_mon_am, id);
	arr_double_index_init(DATABASE_TYPE, 0, db_block_no, db_mon_am);
	arr_index_init(db_block_no, id_copy);
	johnson(db_mon_am, 0, db_block_no, id_copy, result);
	printf("月曜日-午前: ");
	print_result_withid(db_block_no, id_copy, id);

	db_block_no = arr_len(DATABASE_TYPE, db_mon_pm);
	arr_copy(DATABASE_TYPE, db_block_no, 0, db_mon_pm, id);
	arr_double_index_init(DATABASE_TYPE, 0, db_block_no, db_mon_pm);
	arr_index_init(db_block_no, id_copy);
	johnson(db_mon_pm, 0, db_block_no, id_copy, result);
	printf("月曜日-午後: ");
	print_result_withid(db_block_no, id_copy, id);

	db_block_no = arr_len(DATABASE_TYPE, db_tue_am);
	arr_copy(DATABASE_TYPE, db_block_no, 0, db_tue_am, id);
	arr_double_index_init(DATABASE_TYPE, 0, db_block_no, db_tue_am);
	arr_index_init(db_block_no, id_copy);
	johnson(db_tue_am, 0, db_block_no, id_copy, result);
	printf("火曜日-午前: ");
	print_result_withid(db_block_no, id_copy, id);

	db_block_no = arr_len(DATABASE_TYPE, db_tue_pm);
	arr_copy(DATABASE_TYPE, db_block_no, 0, db_tue_pm, id);
	arr_double_index_init(DATABASE_TYPE, 0, db_block_no, db_tue_pm);
	arr_index_init(db_block_no, id_copy);
	johnson(db_tue_pm, 0, db_block_no, id_copy, result);
	printf("火曜日-午後: ");
	print_result_withid(db_block_no, id_copy, id);

	db_block_no = arr_len(DATABASE_TYPE, db_thu_am);
	arr_copy(DATABASE_TYPE, db_block_no, 0, db_thu_am, id);
	arr_double_index_init(DATABASE_TYPE, 0, db_block_no, db_thu_am);
	arr_index_init(db_block_no, id_copy);
	johnson(db_thu_am, 0, db_block_no, id_copy, result);
	printf("木曜日-午前: ");
	print_result_withid(db_block_no, id_copy, id);

	db_block_no = arr_len(DATABASE_TYPE, db_thu_pm);
	arr_copy(DATABASE_TYPE, db_block_no, 0, db_thu_pm, id);
	arr_double_index_init(DATABASE_TYPE, 0, db_block_no, db_thu_pm);
	arr_index_init(db_block_no, id_copy);
	johnson(db_thu_pm, 0, db_block_no, id_copy, result);
	printf("木曜日-午後: ");
	print_result_withid(db_block_no, id_copy, id);

	db_block_no = arr_len(DATABASE_TYPE, db_sat_am);
	arr_copy(DATABASE_TYPE, db_block_no, 0, db_sat_am, id);
	arr_double_index_init(DATABASE_TYPE, 0, db_block_no, db_sat_am);
	arr_index_init(db_block_no, id_copy);
	johnson(db_sat_am, 0, db_block_no, id_copy, result);
	printf("土曜日-午前: ");
	print_result_withid(db_block_no, id_copy, id);

	db_block_no = arr_len(DATABASE_TYPE, db_sat_pm);
	arr_copy(DATABASE_TYPE, db_block_no, 0, db_sat_pm, id);
	arr_double_index_init(DATABASE_TYPE, 0, db_block_no, db_sat_pm);
	arr_index_init(db_block_no, id_copy);
	johnson(db_sat_pm, 0, db_block_no, id_copy, result);
	printf("土曜日-午後: ");
	print_result_withid(db_block_no, id_copy, id);

	printf("program finished!");
	return (0);
}
