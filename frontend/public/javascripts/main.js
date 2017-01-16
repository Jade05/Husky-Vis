$(function() {
	var start = new Date();

	$.post('/vis', {}, function(data) {
		console.log(data);
		console.log(((new Date()).getTime() - start.getTime()) / 1000 + ' s');
	})
});
