create database questao_3_4;
use questao_3_4;
create table artist(
	artist_id int auto_increment primary key,
    artist_name varchar(40)
);
create table album(
	album_id int auto_increment primary key,
    album_name varchar(40),
    artist_id int,
    foreign key (artist_id) references artist(artist_id)
);
create table track(
	track_id int auto_increment primary key,
    track_name varchar(40),
    tempo int,
    album_id int,
    foreign key (album_id) references album(album_id)
);
create table played(
	played int auto_increment primary key,
    track_id int,
	foreign key (track_id) references track(track_id),
    album_id int,
    foreign key (album_id) references album(album_id)
);