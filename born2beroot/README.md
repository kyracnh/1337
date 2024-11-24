crontab: is a background process manager. The specified processes will be executed at the time you specify in the crontab file.

##     To properly configure crontab, we must edit the crontab file with the following command:

```
sudo crontab -u root -e
```

In the file, we must add the following command for the script to execute every 10 minutes 

```
*/10 * * * * sh /path_to_file.sh
```
