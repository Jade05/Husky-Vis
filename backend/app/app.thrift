namespace cpp Server 

struct Suggestion {
    1:required string measure,
    2:required string dimension,
    3:required string chart_type,
    4:required string aggregate_type,
    5:required string statistical_method,
    6:required map<string, double> aggregate_data,
    7:required double score        
}

struct Attribute {
    1:required string name 
}

service App {  
    list<Suggestion> get_suggestions();
    list<Attribute> get_attributes();
} 
