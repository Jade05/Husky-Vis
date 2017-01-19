namespace cpp Visualization  

struct Suggestion {
    1:required string measure,
    2:required string dimension,
    3:required string chart_type,
    4:required string aggregate_type,
    5:require string statistical_method,
    6:required map<string, list<string>> group_by_raw_data,
    7:required map<string, double> aggregate_data,
    8:required double score        
}

struct SuggestionsSet{
    1:required list<Suggestion> allSuggestions
}

struct Attribute {
    1:required string attribute
}

struct AttributesSet {
    1:required list<Attribute> allAttributes
}

service App {  
    SuggestionSet ping(); 
    list<string> init_run();
} 
