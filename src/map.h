#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

typedef enum
{
	mt_none		= 0,
	mt_egg		= 1,
	mt_stone	= 2,
	mt_fund		= 3,
	mt_flav		= 4,
	mt_ice		= 5
}	m_type;

typedef struct
{
	m_type	type;
	u8		go;
}			t_map;

#endif // MAP_H_INCLUDED
