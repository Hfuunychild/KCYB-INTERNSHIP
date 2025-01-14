#ifndef H_GRID_H_
#define H_GRID_H_

#include<pthread.h>
#include "server/grid/lbs_defs.h"
#include "server/grid/hashtable.h"

typedef struct lbs_cell_S{
	//dammy node
	lbs_mov_node_t dammy_node;
	//lock
	pthread_mutex_t mutex;	
}lbs_cell_t;

typedef struct lbs_grid_s{
	//row num of grid
	int row_num;
	//col num of grid
	int col_num;
	//cell width
	double cell_width;
	//cell height
	double cell_height;
	//grid lon minimum value
	double lon_min;
	//grid lat minimum value
	double lat_min;
	//hash table
	lbs_hashtable_t hash_table;
	lbs_cell_t* cell;
}lbs_grid_t;

//网络的初始化
int lbs_grid_init(lbs_grid_t* lbs_grid, double lon1, double lon2, double lat1, double lat2, int row_num, int col_num);

//更新移动位置
int lbs_grid_update(lbs_grid_t* lbs_grid, double lon, double lat, uint64_t timestamp, uint32_t id);
//计算cell row
int lbs_grid_cell_row(lbs_grid_t* lbs_grid,double lat);
//计算 cell col
int lbs_grid_cell_col(lbs_grid_t* lbs_grid, double lon);
//计算 cell id
int lbs_grid_cell_id(lbs_grid_t* lbs_grid,int cell_row, int cell_col);
//计算row和col
void lbs_grid_cell_row_col(lbs_grid_t* lbs_grid, int cell_id, int* cell_row, int* cell_col);
//获取cell id里面的cell 
lbs_cell_t* lbs_grid_cell(lbs_grid_t* lbs_grid, int cell_id);

#endif
