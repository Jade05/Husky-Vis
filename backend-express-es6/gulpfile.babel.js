import gulp from 'gulp';
import watch from 'gulp-watch';
import babel from 'gulp-babel';
import sourcemaps from 'gulp-sourcemaps';
import relativeSourcemapsSource from 'gulp-relative-sourcemaps-source';
import livereload from 'gulp-livereload';
import uglify from 'gulp-uglify';
import polyfiller from 'gulp-polyfiller';

gulp.task('build', () => {
  return gulp.src('src/**/*.js')
  .pipe(sourcemaps.init())
  // push polyfills file after all scripts 
  .pipe(polyfiller(['Promise', 'Fetch']))
  .pipe(babel())
  .pipe(relativeSourcemapsSource({dest: 'dist'}))
  .pipe(sourcemaps.write('.', {
    includeContent: false,
    sourceRoot: '.'
  }))
  .pipe(gulp.dest('dist'))
  .pipe(livereload());
});

gulp.task('watch', ['build'], function () {
    livereload.listen();
    gulp.watch('src/**/*.js', ['build']);
});

gulp.task('default', ['build', 'watch']);
