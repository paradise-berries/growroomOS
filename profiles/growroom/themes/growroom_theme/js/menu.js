(function ($) {
  Drupal.behaviors.growroom_theme_menu = {
    attach: function(context, settings) {
      if (settings.growroom_theme.menu_dividers) {
        var dividers = settings.growroom_theme.menu_dividers;
        var menus = ['assets','WIP', 'logs', 'plans'];
        var weights = [0, 100];
        for (var i = 0; i < menus.length; i++) {
          if (dividers[menus[i]] !== undefined) {
            for (var j = 0; j < weights.length; j++) {
              if (dividers[menus[i]][weights[j]] !== undefined) {
                var li = dividers[menus[i]][weights[j]];
                $('.nav .dropdown .' + menus[i], context).siblings('.dropdown-menu').children('li:eq(' + li + ')').after($('<li class="divider"></li>'));
              }
            }
          }
        }
      }
    }
  }
})(jQuery);
