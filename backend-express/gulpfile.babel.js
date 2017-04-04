import gulp from 'gulp';
import watch from 'gulp-watch';
import babel from 'gulp-babel';

gulp.task('transform', () => {
  return gulp.src('*.js')
    .pipe(babel())
    .pipe(gulp.dest('lib'));
});

gulp.task('watch', () => {
  return gulp.src('*.js')
    .pipe(watch('*.js', {
      verbose: true
    }))
    .pipe(babel())
    .pipe(gulp.dest('lib'));
});

gulp.task('default', () => {
  gulp.start('transform');
});
