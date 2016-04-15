$( document ).ready(function() {
  toto();
});

function toto()
{
  $.getJSON( "./server.php?get=ships", function( data ) {
    var items = [];
    $.each( data, function( key, val ) {

      $('.case_'+val.x+'_'+val.y).addClass('v'+val.owner).click(function( event ) {
        clickOnShip(event);
      });
    });
  });

  $.getJSON( "./server.php?get=asteroid", function( data ) {
    var items = [];
    $.each( data, function( key, val ) {
      $('.case_'+val.x+'_'+val.y).addClass('a');
    });
  });
}

function clickOnShip(event)
{
  console.log(event.target.className);

  $.get( "./server.php?get=ship", { class: event.target.className } )
    .done(function( data ) {
      $("#panel").html(data);


      $(".panel-btn").click(function(){
        // Holds the product ID of the clicked element
        var productId = $(this).attr('id');
          //console.log("./server.php?action=btn&id="+productId+"&nb="+$("#nb").val());
        $.get( "./server.php?action=btn&id="+productId+"&nb="+$("#nb").val())
          .done(function( data ) {
            console.log(data);
          });

      });



    });



}
