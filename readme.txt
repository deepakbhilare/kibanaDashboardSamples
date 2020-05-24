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



