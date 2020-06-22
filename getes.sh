cd /Users/deepakbhilare/Documents/elastic_search/

echo "DOWNLOADING ES $1"
(curl https://artifacts.elastic.co/downloads/elasticsearch/elasticsearch-$1-darwin-x86_64.tar.gz --output elasticsearch-$1-darwin-x86_64.tar.gz )&& (gunzip elasticsearch-$1-darwin-x86_64.tar.gz && tar -xvf elasticsearch-$1-darwin-x86_64.tar)

echo "DOWNLOADING KIBANA $1"
(curl https://artifacts.elastic.co/downloads/kibana/kibana-$1-darwin-x86_64.tar.gz --output kibana-$1-darwin-x86_64.tar.gz)&& (gunzip kibana-$1-darwin-x86_64.tar.gz && tar -xvf kibana-$1-darwin-x86_64.tar)

echo "DOWNLOADING LOGSTASH $1"
(curl https://artifacts.elastic.co/downloads/logstash/logstash-$1.tar.gz --output logstash-$1.tar.gz) && (gunzip logstash-$1.tar.gz && tar -xvf logstash-$1.tar)

echo "DOWNLOADING FILEBEAT $1"
(curl https://artifacts.elastic.co/downloads/beats/filebeat/filebeat-$1-darwin-x86_64.tar.gz --output filebeat-$1-darwin-x86_64.tar.gz) && (gunzip filebeat-$1-darwin-x86_64.tar.gz && tar -xvf filebeat-$1-darwin-x86_64.tar)
