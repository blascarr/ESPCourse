$('#toggle').click(
    function() {
        $.get("server_endpoint", {"server_data":  $('#toggle')[0].checked });
    }
);