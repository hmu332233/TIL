## [MYSQL] foreign key 무시하고 테이블 삭제하기


외래키 때문에 테이블 삭제가 안되는 경우
```
ERROR 1217 (23000): Cannot delete or update a parent row: a foreign key constraint fails
```
다음과 같이하면 삭제가 가능하다
```
mysql> SET foreign_key_checks = 0;
mysql> drop table TABLENAME
mysql> SET foreign_key_checks = 1;
```
