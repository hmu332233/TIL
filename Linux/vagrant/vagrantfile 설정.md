## vagrantfile 설정

### 포트 포워딩
```
config.vm.network :forwarded_port, guest: 80, host: 8080
```
### 폴더 동기화
```
config.vm.synced_folder "E:\\vagrant\\common_source_folder", "/vagrant_data"
```
