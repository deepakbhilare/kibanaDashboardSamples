curl -u elastic -H 'Content-Type: application/x-ndjson' -XPOST 'localhost:9200/mylog/_bulk?pretty' --data-binary @mylog.json

GET _cat/indices/v
GET /mylog/_mapping
DELETE mylog
GET /shakespeare/_mapping
PUT mylog
{
  "mappings": {
    "properties": {
      "date": {
        "type": "date" ,
	   "format" : "dd/MM/yyyy"
      },
	"scenarioid" : {
		"type" : "keyword"
	},
	"srvname" : {
		"type" : "keyword"
	},
	"result" : {
		"type" : "keyword"
	},
	"remarks" : {
		"type" : "keyword"
	}
    }
  }
}


---------------------
logstash
---------
curl -XGET 'localhost:9600/_node/logging?pretty'

curl -XPUT 'localhost:9600/_node/logging?pretty' -H 'Content-Type: application/json' -d'
{
    "logger.logstash.outputs.elasticsearch" : "DEBUG"
}
'

curl -XPUT 'localhost:9600/_node/logging/reset?pretty'

logstash.yml
--------------
slowlog.threshold.warn (default: -1)

Configuring Logstashedit
----------------------------
input { stdin { } }
output {
  elasticsearch { hosts => ["localhost:9200"] }
  stdout { codec => rubydebug }
}

bin/logstash -f logstash-simple.conf

GET _search
{
  "query": {
    "match_all": {}
  }
}

PUT .kibana/_settings
{
  "index": {
    "blocks": {
      "read_only_allow_delete": "false"
    }
  }
}

PUT _settings
{
  "index": {
    "blocks": {
      "read_only_allow_delete": "false"
    }
  }
}
PUT mylog/_settings
{
  "index": {
    "blocks": {
      "read_only_allow_delete": "false"
    }
  }
}

readonly index
-----------------

curl -XPUT -H "Content-Type: application/json" http://localhost:9200/_all/_settings -d '{"index.blocks.read_only_allow_delete": null}'


How to disable ElasticSearch disk quota / watermark
------------------------------------------------------
curl -X PUT "localhost:9200/_cluster/settings" -H 'Content-Type: application/json' -d'
{
  "transient": {
    "cluster.routing.allocation.disk.watermark.low": "30mb",
    "cluster.routing.allocation.disk.watermark.high": "20mb",
    "cluster.routing.allocation.disk.watermark.flood_stage": "10mb",
    "cluster.info.update.interval": "1m"
  }
}
'

curl -XPUT -H "Content-Type: application/json" http://localhost:9200/_all/_settings -d '{"index.blocks.read_only_allow_delete": null}'

curl -XGET "http://localhost:9200/_cat/allocation?v&pretty"

----------------------------------------------------

[2020-06-01T22:25:53,348][INFO ][logstash.outputs.elasticsearch][main][d96b78db5ecdf32039c7dcb9d708329d4eed25d40bbe86f779f85d6bbe0b1280] retrying failed action with response code: 403 ({"type"=>"cluster_block_exception", "reason"=>"index [logstash] blocked by: [FORBIDDEN/12/index read-only / allow delete (api)];"})
------------------------------------------------------
https://www.elastic.co/guide/en/elasticsearch/reference/current/search-request-body.html#request-body-search-queries-and-filters
------------------------------------------------------
https://dzone.com/articles/23-useful-elasticsearch-example-queries
https://logz.io/blog/elasticsearch-queries/
-----------------------------------------------------
raspberry pi and alexa
https://circuitdigest.com/microcontroller-projects/voice-controlled-home-automation-using-amazon-alexa-and-raspberry-pi
https://www.instructables.com/id/RASPBERRY-PI-ALEXA-HOME-AUTOMATION/

